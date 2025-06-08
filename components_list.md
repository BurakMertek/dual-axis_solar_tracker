# Hardware Components List

## Main Components

### Microcontroller
- **Arduino Nano**
  - Microcontroller: ATmega328
  - Operating voltage: 5V
  - Supply voltage: 7-12V (recommended)
  - Digital I/O pins: 14
  - PWM pins: 6
  - Analog input pins: 8
  - Flash memory: 32 kB
  - Clock speed: 16 MHz

### Solar Panel
- **6V 150mA Solar Module**
  - Rated voltage: 6V
  - Rated current: 150mA
  - Open-circuit voltage: 6.5 VDC
  - Short-circuit current: 170 mA
  - Maximum power: 0.90W
  - Dimensions: 105mm x 66mm x 3mm

### Servo Motors
- **2x SG90 Servo Motors**
  - Operating voltage: 4.8V - 6V
  - Torque: 2.5 kg⋅cm (4.8V), 3.0 kg⋅cm (6V)
  - Speed: 0.1 s/60° (4.8V), 0.08 s/60° (6V)
  - Rotation range: 180°
  - Control signal: PWM (20ms period)

### Sensors
- **4x LDR (Light Dependent Resistor)**
  - Type: 5mm photoresistor
  - Resistance range: 1kΩ - 10MΩ
  - Response time: 20-30ms
  - Peak wavelength: 540nm

- **INA219 Current/Voltage Sensor**
  - Voltage range: 0-26V
  - Current range: ±3.2A
  - Resolution: 0.1mA, 4mV
  - Interface: I2C
  - Address: 0x40 (default)

### Display
- **I2C OLED Display**
  - Size: 128x64 pixels
  - Color: Monochrome (white)
  - Interface: I2C
  - Operating voltage: 3.3V - 5V
  - Viewing angle: >160°

### Power Management
- **TP4056 Battery Charger Module**
  - Input voltage: 4.5V - 5.5V
  - Charging current: 1A (adjustable)
  - Battery type: Single cell Li-ion/Li-Po
  - Protection: Over-charge, over-discharge, over-current

- **3.7V LiPo Battery**
  - Capacity: 950mAh
  - Nominal voltage: 3.7V
  - Charging voltage: 4.2V
  - Connector: JST-PH
  - C-rating: 30C continuous

## Additional Components

### Resistors
- 4x 10kΩ resistors (for LDR voltage dividers)
- 2x 220Ω resistors (LED current limiting)

### Capacitors
- 2x 100μF electrolytic capacitors (power supply filtering)
- 4x 100nF ceramic capacitors (decoupling)

### Connectors
- Header pins (male/female)
- Jumper wires
- Breadboard or PCB
- Screw terminals

### Mechanical Parts
- 3D printed structure components
- M3 screws and nuts
- Ball bearings (for smooth rotation)
- Mounting brackets

## Tools Required
- Soldering iron and solder
- Wire strippers
- Multimeter
- 3D printer (for mechanical parts)
- Computer for programming

## Estimated Total Cost
- **Budget version**: ~$50-70 USD
- **Professional version**: ~$80-120 USD

*Prices may vary based on supplier and region*