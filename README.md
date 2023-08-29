# SkySeeker

SkySeeker is a complete DIY software and hardware antenna tracker solution for drones (UAVs, RPAs profesionals and FPV hobbyists). SkySeeker is a follow-up project of the famous U360GTS Tracker System. Since the U360GTS Project has not seen much development, while in a very advanced state with a lot of potential left behind, we dicided to build up on this fantastic base and start the SkySeeker Project to push further development. It is the perfect option if you need to track different aircrafts with different telemetry protocols. Firmware and hardware design have been developed by members of FPV community and are released for free under the GPLv3 license.

You are encouraged to read all the [documentation](docs/README.md) before using this firmware in your devices in order to prevent damages, unexpected behavior and misconfiguration.

## Hardware platform 

This firmware has been developed for controllers based on STM32 F1 and F3 series microprocessors, such as the popular NAZE32 or SPRacingF3 and their clones. Flight controllers **without** an onboard magnetometer are to be preferred. As these Flight Controllers are nowadays very hard to get, we are working on support for more up to date hardware in the near future. This includes especially F411 and F405 based Flight controllers, that are widely available today and many of us have in their parts drawer anyway. 

# Features

* 360° continous rotation.
* Multiprotocol.
* Automatic protocol detection.
* Up to 10 Hz telemetry input.
* Protocol conversion and forwarding.
* Configurable via [SkySeeker-configurator](https://github.com/SuperKohl/SkySeeker-configurator) (cross platform) and serial console (CLI mode).
* Tilt easing.
* Automatic home position.
* Detailed status data on OLED display.
* Battery monitoring.
* RSSI signal strength on OLED display.
* Setup menu on OLED display.
* Accurate PID control system.
* Position estimation system.
* Sound alarms via buzzer.
* Multiple Serial ports, with dynamic assignment.

Take a look at the [overview](docs/overview.md) to read more about the features listed above.

# Releases

Check out the [releases](https://github.com/SuperKohl/SkySeeker/releases) page.

# How To Get Help

- [Submit a new issue](https://github.com/SuperKohl/SkySeeker/issues)

# Thanks

Thaks to Raúl Ortega [u360gts](https://github.com/raul-ortega/u360gts) page.
