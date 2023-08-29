/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>

#include "platform.h"

#include "common/axis.h"

#include "drivers/sensor.h"
#include "drivers/compass.h"
#include "drivers/compass_hmc5883l.h"
#include "drivers/compass_qmc5883l.h"

#include "drivers/gpio.h"
#include "drivers/light_led.h"

#include "sensors/boardalignment.h"
#include "config/runtime_config.h"
#include "config/config.h"

#include "sensors/sensors.h"
#include "sensors/compass.h"

#include "tracker/config.h"
#include "drivers/pwm_output.h"

#ifdef NAZE
#include "hardware_revision.h"
#endif

#include "tracker/config.h"
#include "io/display.h"

#include "tracker/servos.h"

mag_t mag;                   // mag access functions

extern uint32_t currentTime; // FIXME dependency on global variable, pass it in instead.

extern uint8_t pwmPanPin;
extern uint16_t pwmPan0;
extern uint16_t pwmPanCalibrationPulse;

extern uint8_t cliMode;

int16_t magADC[XYZ_AXIS_COUNT];
sensor_align_e magAlign = 0;
#ifdef MAG
static uint8_t magInit = 0;

void compassInit(void)
{
    // initialize and calibration. turn on led during mag calibration (calibration routine blinks it)
    LED1_ON;
    mag.init();
    LED1_OFF;
    magInit = 1;
}

#define COMPASS_UPDATE_FREQUENCY_10HZ (1000 * 100)

void updateCompass(flightDynamicsTrims_t *magZero)
{
    static uint32_t nextUpdateAt, tCal = 0;
    static flightDynamicsTrims_t magZeroTempMin;
    static flightDynamicsTrims_t magZeroTempMax;
    uint32_t axis;
    if(detectedSensors[SENSOR_INDEX_MAG] != MAG_NONE){
		if ((int32_t)(currentTime - nextUpdateAt) < 0)
			return;

		nextUpdateAt = currentTime + COMPASS_UPDATE_FREQUENCY_10HZ;

		mag.read(magADC);
		alignSensors(magADC, magADC, magAlign);

		if (STATE(CALIBRATE_MAG)) {
			tCal = nextUpdateAt;
			for (axis = 0; axis < 3; axis++) {
				magZero->raw[axis] = 0;
				magZeroTempMin.raw[axis] = magADC[axis];
				magZeroTempMax.raw[axis] = magADC[axis];
			}
			DISABLE_STATE(CALIBRATE_MAG);
			ENABLE_PROTOCOL(TP_CALIBRATING_MAG);
			displayShowFixedPage(PAGE_CALIBRATING_MAG);
			displayResetPageCycling();
			displayDisablePageCycling();
			pwmWriteServo(pwmPanPin, pwmPanCalibrationPulse);
		}

		if (magInit) {              // we apply offset only once mag calibration is done
			magADC[X] -= magZero->raw[X];
			magADC[Y] -= magZero->raw[Y];
			magADC[Z] -= magZero->raw[Z];
		}

		if (tCal != 0) {
			if ((nextUpdateAt - tCal) < 10000000){//30000000) {    // 30s: you have 30s to turn the multi in all directions
				LED0_TOGGLE;
				for (axis = 0; axis < 3; axis++) {
					if (magADC[axis] < magZeroTempMin.raw[axis])
						magZeroTempMin.raw[axis] = magADC[axis];
					if (magADC[axis] > magZeroTempMax.raw[axis])
						magZeroTempMax.raw[axis] = magADC[axis];
				}
			} else {
				tCal = 0;
				for (axis = 0; axis < 3; axis++) {
					magZero->raw[axis] = (magZeroTempMin.raw[axis] + magZeroTempMax.raw[axis]) / 2; // Calculate offsets
				}
				pwmWriteServo(pwmPanPin, pwmPan0);
				DISABLE_PROTOCOL(TP_CALIBRATING_MAG);

				if(cliMode && feature(FEATURE_DISPLAY)) {
					displayShowFixedPage(PAGE_CLI_MODE);

				}
				else {
					displayResetPageCycling();
					displayEnablePageCycling();
				}
				saveConfigAndNotify();
			}
		}
    }
}
#endif
