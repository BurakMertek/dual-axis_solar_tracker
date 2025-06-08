# Dual-Axis Solar Tracker Performance Data

**Repository:** [dual-axis_solar_tracker](https://github.com/BurakMertek/dual-axis_solar_tracker)

## System Specifications
- **Tracker Type:** Dual-axis (azimuth and elevation)
- **Control System:** Arduino-based with servo motors
- **Sensor Array:** LDR-based light detection system

## Performance Measurements

### Electrical Output Data
| Parameter | Value | Unit |
|-----------|-------|------|
| Voltage   | 0.03  | V    |
| Current   | 0.70  | mA   |
| Power     | 0.02  | mW   |
| Energy Accumulated| 3115.66 | mWh |

### Tracking Performance
- **LDR Response Time:** ~500ms
- **Tracking Resolution:** ±2° accuracy
- **Azimuth Range:** 0° to 180°
- **Elevation Range:** 0° to 90°
- **Positioning Accuracy:** ±1°

## Test Conditions
- **Environment:** Indoor laboratory testing
- **Light Source:** LED panel array
- **Temperature:** 20-25°C

## Performance Analysis
The dual-axis tracking system demonstrates reliable light detection and positioning. The servo-based control provides sufficient precision for educational applications with successful proof-of-concept operation.

### System Response
- **Startup Time:** ~3 seconds
- **Tracking Update Rate:** Every 5 seconds

## Future Improvements
- Larger solar panel for increased power generation
- Weather protection for outdoor deployment
- Enhanced data logging capabilities