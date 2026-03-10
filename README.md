# Arduino Compost Monitor

An Arduino-based compost monitoring system for temperature, moisture, and environmental sensing with reproducible firmware, calibration notes, and sustainability-oriented monitoring documentation.

This project is designed as a reproducible prototype for engineers, students, and researchers interested in biological process monitoring, embedded sensing, and sustainable waste systems.

## Overview

The system monitors compost-relevant conditions using low-cost sensors and Arduino-based telemetry.

At a systems level, the architecture can be summarized as:

Compost Bin → Temperature / Moisture Sensors → Arduino → Telemetry / Logging / Future Control

## Features

- compost temperature sensing
- moisture-related signal monitoring
- optional ambient temperature and humidity sensing
- Arduino-based telemetry
- calibration and deployment notes
- extensible for logging, alerts, or automation

## Repository Structure

- `firmware/` — Arduino monitoring firmware
- `docs/` — setup, calibration, and deployment documentation
- `data/` — example compost readings
- `hardware/` — wiring diagrams and schematics
- `BOM.csv` — bill of materials

## Notes

This is a prototype reference design, not an industrial compost instrumentation platform. Engineers adapting it for longer-term use should validate sensor durability, enclosure design, moisture exposure, and long-term measurement stability.

## License

This project is released under the MIT License.

See `LICENSE` for details.
