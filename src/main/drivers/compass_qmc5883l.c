/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include <math.h>

#include "platform.h"
#include "debug.h"

#include "common/axis.h"
#include "common/maths.h"

#include "system.h"
#include "nvic.h"
#include "gpio.h"
#include "bus_i2c.h"
#include "light_led.h"

#include "sensor.h"
#include "compass.h"

#include "sensors/sensors.h"

#include "compass_qmc5883l.h"

#define QMC5883L_MAG_I2C_ADDRESS 0x0D

// Registers
#define QMC5883L_REG_CONF1 0x09
#define QMC5883L_REG_CONF2 0x0A

// data output rates for 5883L
#define QMC5883L_ODR_10HZ  (0x00 << 2)
#define QMC5883L_ODR_50HZ  (0x01 << 2)
#define QMC5883L_ODR_100HZ (0x02 << 2)
#define QMC5883L_ODR_200HZ (0x03 << 2)

// Sensor operation modes
#define QMC5883L_MODE_STANDBY    0x00
#define QMC5883L_MODE_CONTINUOUS 0x01

#define QMC5883L_RNG_2G (0x00 << 4)
#define QMC5883L_RNG_8G (0x01 << 4)

#define QMC5883L_OSR_512 (0x00 << 6)
#define QMC5883L_OSR_256 (0x01 << 6)
#define QMC5883L_OSR_128 (0x10 << 6)
#define QMC5883L_OSR_64  (0x11 << 6)

#define QMC5883L_RST 0x80

#define QMC5883L_REG_DATA_OUTPUT_X 0x00
#define QMC5883L_REG_STATUS 0x06

#define QMC5883L_REG_ID 0x0D
#define QMC5883_ID_VAL 0xFF

void qmc5883lInit(void)
{
    //UNUSED(mag);

    bool ack = true;

    ack = ack && i2cWrite(QMC5883L_MAG_I2C_ADDRESS, 0x0B, 0x01);
    ack = ack && i2cWrite(QMC5883L_MAG_I2C_ADDRESS, QMC5883L_REG_CONF1, QMC5883L_MODE_CONTINUOUS | QMC5883L_ODR_200HZ | QMC5883L_OSR_512 | QMC5883L_RNG_8G);
/*
    if (!ack) {
        return false;
    }
*/
    //return true;
}

bool qmc5883lRead(int16_t *magData)
{
    uint8_t status;
    uint8_t buf[6];

    // set magData to zero for case of failed read
    magData[X] = 0;
    magData[Y] = 0;
    magData[Z] = 0;

    bool ack = i2cRead(QMC5883L_MAG_I2C_ADDRESS, QMC5883L_REG_STATUS, 1, &status);

    if (!ack || (status & 0x04) == 0) {
        return false;
    }

    ack = i2cRead(QMC5883L_MAG_I2C_ADDRESS, QMC5883L_REG_DATA_OUTPUT_X, 6, buf);
    if (!ack) {
        return false;
    }

    magData[X] = (int16_t)(buf[1] << 8 | buf[0]);
    magData[Y] = (int16_t)(buf[3] << 8 | buf[2]);
    magData[Z] = (int16_t)(buf[5] << 8 | buf[4]);

    return true;
}

bool qmc5883lDetect(mag_t* mag, const qmc5883lConfig_t *qmc5883lConfigToUse)
{
    // Must write reset first  - don't care about the result
    i2cWrite(QMC5883L_MAG_I2C_ADDRESS,QMC5883L_REG_CONF2, QMC5883L_RST);
    delay(20);

    uint8_t sig = 0;
    bool ack = i2cRead(QMC5883L_MAG_I2C_ADDRESS, QMC5883L_REG_ID, 1, &sig);
    if (ack && sig == QMC5883_ID_VAL) {
        // Should be in standby mode after soft reset and sensor is really present
        // Reading ChipID of 0xFF alone is not sufficient to be sure the QMC is present
        ack = i2cRead(QMC5883L_MAG_I2C_ADDRESS, QMC5883L_REG_CONF1, 1, &sig);
        if (ack && sig != QMC5883L_MODE_STANDBY) {
            return false;
        }
        mag->init = qmc5883lInit;
        mag->read = qmc5883lRead;
        return true;
    }

    return false;
    
}
