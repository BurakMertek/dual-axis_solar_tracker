# Dual-Axis Solar Tracking System

A dual-axis solar tracking control system that maximizes solar energy collection by automatically orienting solar panels to follow the sun's movement throughout the day.

## Features

- **Dual-axis tracking**: Horizontal and vertical movement for optimal sun alignment
- **LDR-based sensing**: Four light-dependent resistors for precise light detection
- **Arduino control**: Arduino Nano-based control system
- **Power monitoring**: Real-time power generation logging with INA219 sensor
- **OLED Display**: Real-time data visualization
- **Battery management**: TP4056-based LiPo battery charging system
- **3D printed structure**: Custom mechanical housing for components

## Hardware Components

- Arduino Nano
- 2x Servo motors (SG90)
- 4x LDR (Light Dependent Resistor) sensors
- 6V 150mA Solar panel
- INA219 current/voltage sensor
- I2C OLED display (128x64)
- TP4056 battery charger module
- 3.7V LiPo battery
- 3D printed mechanical structure

## Performance

- **Energy gain**: Up to 40% more energy compared to fixed solar panels
- **Power consumption**: 33.4% less energy consumption than continuous tracking systems
- **Tracking accuracy**: Maintains optimal alignment throughout daylight hours

## Repository Structure

```
├── src/
│   ├── solar_tracker.ino      # Main tracking control code
│   ├── power_logger.ino       # Power monitoring system
│   └── solar_position.py      # Solar position calculation (Python)
├── hardware/
│   ├── circuit_diagram.png    # Circuit schematic
│   └── components_list.md     # Detailed component specifications
├── 3d_models/
│   ├── pan_tilt_base.stl     # 3D printable base
│   ├── pan_tilt_platform.stl # 3D printable platform
│   └── pan_tilt_top.stl      # 3D printable top piece
└── docs/
    ├── setup_guide.md        # Assembly and setup instructions
    └── performance_data.md   # Test results and analysis

```

## Quick Start

1. **Hardware Assembly**: Follow the circuit diagram in `/hardware/`
2. **3D Printing**: Print the mechanical parts from `/3d_models/`
3. **Code Upload**: Flash the Arduino code from `/src/`
4. **Calibration**: Adjust LDR positioning for optimal light detection

## Circuit Connection

- **LDR Sensors**: A0-A3 (top-left, top-right, bottom-left, bottom-right)
- **Servo Motors**: Pin 9 (horizontal), Pin 10 (vertical)
- **Power Supply**: 7-12V for Arduino, separate 5V for servos
- **INA219**: I2C connection (SDA, SCL)
- **OLED Display**: I2C connection (SDA, SCL)

## License

This project is open source and available under the [MIT License](LICENSE).

## Authors

- Çağatay Yılmaz
- Fatih Yiğit  
- Recep Kutlay Tumay
- Burak Metin Mertek

**Supervisor**: Prof. Dr. Zıyodulla YUSUPOV

**Institution**: Karabük University, Faculty of Engineering, Electrical-Electronics Engineering Department

## Acknowledgments

Special thanks to Karabük University for supporting this research project and providing the necessary resources for development and testing.