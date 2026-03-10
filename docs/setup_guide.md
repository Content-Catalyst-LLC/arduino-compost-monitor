# Setup Guide

## Purpose

This guide explains how to assemble and test the Arduino Compost Monitor prototype.

## Wiring Overview

### DS18B20 Temperature Sensor

- VCC → 5V
- GND → GND
- DATA → Arduino D2

Add a 10kΩ pull-up resistor between DATA and VCC.

### DHT22 Ambient Sensor (Optional)

- VCC → 5V
- GND → GND
- DATA → Arduino D3

### Capacitive Moisture Sensor

- VCC → 5V
- GND → GND
- Signal → A0

## Build Steps

1. Connect the DS18B20 waterproof probe to the Arduino
2. Add the 10kΩ pull-up resistor for the DS18B20 data line
3. Connect the optional DHT22 ambient sensor
4. Connect the capacitive moisture sensor to A0
5. Upload `compost_monitor.ino`
6. Open the Serial Monitor at `9600` baud
7. Place the sensors appropriately and observe readings

## Validation

Before relying on the prototype, verify:

- the DS18B20 reports stable temperatures
- the DHT22 returns valid ambient readings
- the moisture signal changes under different compost conditions
- serial telemetry remains clear and stable
