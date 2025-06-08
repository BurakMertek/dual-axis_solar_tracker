# Setup and Assembly Guide

## Step 1: 3D Printing

Print the following parts using PLA or PETG filament:
- `pan_tilt_base.stl` - Base platform
- `pan_tilt_platform.stl` - Moving platform  
- `pan_tilt_top.stl` - Top mounting piece

**Print Settings:**
- Layer height: 0.2mm
- Infill: 20%
- Support: Yes (for overhangs)
- Print speed: 50mm/s

## Step 2: Circuit Assembly

### LDR Sensor Circuit
1. Create voltage dividers for each LDR:
   - Connect LDR between 5V and analog pin
   - Connect 10kΩ resistor between analog pin and GND
   - Repeat for all 4 LDRs (pins A0-A3)

### Servo Motor Connections
- Horizontal servo → Pin 9
- Vertical servo → Pin 10
- Red wire (power) → 5V
- Brown/Black wire (ground) → GND
- Orange/Yellow wire (signal) → Digital pin

### Power Logger Circuit
- INA219: SDA → A4, SCL → A5, VCC → 3.3V, GND → GND
- OLED Display: SDA → A4, SCL → A5, VCC → 3.3V, GND → GND
- TP4056: Connect to solar panel (+) and (-) terminals

## Step 3: Mechanical Assembly

1. **Base Assembly:**
   - Mount horizontal servo to base using M3 screws
   - Attach servo horn to base platform

2. **Platform Assembly:**
   - Mount vertical servo to platform
   - Attach solar panel to top piece
   - Connect top piece to vertical servo horn

3. **LDR Positioning:**
   - Mount 4 LDRs in corners of solar panel
   - Ensure equal spacing and clear exposure to light
   - Use small tubes or shields to prevent cross-lighting

## Step 4: Programming

### Arduino IDE Setup
1. Install required libraries:
   ```
   Adafruit_INA219
   SSD1306Ascii
   SdFat (optional for logging)
   ```

2. Flash the main tracking code:
   - Open `solar_tracker.ino`
   - Select Arduino Nano from board menu
   - Upload to Arduino

3. Flash the power logger code (separate Arduino):
   - Open `power_logger.ino`
   - Upload to second Arduino Nano

## Step 5: Calibration

### LDR Calibration
1. Position system facing east at sunrise
2. Check LDR readings using Serial Monitor
3. Adjust LDR positioning if readings are unbalanced
4. Test tracking by moving light source around panel

### Servo Calibration
1. Set servos to center position (90°)
2. Adjust mechanical alignment
3. Test full range of motion (0° to 180°)
4. Set software limits to prevent mechanical collision

## Step 6: Testing

### Initial Tests
1. **Power Test:** Verify 5V supply to all components
2. **Servo Test:** Manual servo movement using test code
3. **LDR Test:** Check light sensitivity and readings
4. **Display Test:** Verify OLED shows power data

### System Integration Test
1. Position system outdoors in direct sunlight
2. Observe automatic tracking behavior
3. Monitor power generation on OLED display
4. Check data logging functionality

## Troubleshooting

### Common Issues

**Servos not moving:**
- Check power supply (servos need 5V, 1A minimum)
- Verify PWM signal connections
- Test servo individually with simple code

**Erratic tracking:**
- Shield LDRs from cross-lighting
- Adjust LDR positioning
- Add delays in control loop
- Check for loose connections

**No power readings:**
- Verify INA219 I2C connections
- Check solar panel polarity
- Ensure adequate sunlight

**Display not working:**
- Check I2C address (usually 0x3C)
- Verify power supply (3.3V or 5V)
- Test with I2C scanner code

## Maintenance

### Daily
- Clean solar panel surface
- Check for loose connections
- Monitor power output

### Weekly  
- Inspect mechanical joints
- Test full range of motion
- Clean LDR sensors

### Monthly
- Check battery voltage and charging
- Calibrate LDR readings
- Update tracking limits if needed

## Safety Notes

⚠️ **Important Safety Information:**
- Always disconnect power when making connections
- Use appropriate voltage levels (5V for logic, 12V max for power)
- Secure all outdoor installations against weather
- Monitor battery temperature during charging
- Use fuses for power circuits

## Performance Optimization

### Improve Tracking Accuracy
- Add more LDR sensors for better precision
- Implement hysteresis in control algorithm
- Use higher resolution servos

### Increase Power Generation
- Optimize panel angle for your latitude
- Implement maximum power point tracking (MPPT)
- Use larger capacity battery for energy storage

### Weather Protection
- Add rain sensor to park system during storms
- Implement wind speed monitoring
- Use weatherproof enclosures for electronics