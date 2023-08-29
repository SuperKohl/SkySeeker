# SkySeeker

SkySeeker is a complete DIY software and hardware antenna tracker solution for drones (UAVs, RPAs profesionals and FPV hobbyists). We tried to make it as universal as possible in terms of being compatible with the most popular F1/F3 flight controllers, radio and video systems. It is the perfect option if you need to track different aircrafts with different telemetry protocols. Firmware and hardware design have been developed by members of FPV community and are released for free under the GPLv3 license.

You are encouraged to read all the [documentation](docs/README.md) before using this firmware in your devices in order to prevent damages, unexpected behavior and misconfiguration.

## Hardware platform 

This firmware has been developed for controllers based on STM32 F1 and F3 series microprocessors, such as the popular NAZE32 and its clones. By now it has been tested on other boards such as the Flip32 and a barebone Bluepill. Flight controllers **without** an onboard magnetometer are to be preferred.

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
* 4 Serial ports, with dynamic assignment.

Take a look at the [overview](docs/overview.md) to read more about the features listed above.

# Releases

Check out the [releases](https://github.com/SuperKohl/SkySeeker/releases) page.

# How To Get Help

- [Submit a new issue](https://github.com/SuperKohl/SkySeeker/issues)