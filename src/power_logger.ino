/*
 * Solar Power Logger System
 * Power monitoring and data logging for solar tracking system
 * 
 * Components:
 * - INA219 current/voltage sensor
 * - I2C OLED display
 * - TP4056 battery charger
 */

 #include <Adafruit_INA219.h>
#include <SSD1306AsciiAvrI2c.h>
#include <SdFat.h>

volatile boolean triggered = false;

#define OLED_RESET 4
SSD1306AsciiAvrI2c display;

Adafruit_INA219 ina219;
float current_mA = 0.0, oldcurr = 0.0;
float loadvoltage = 0.0, oldvolt = 0.0;
float power_mW = 0.0, oldpow = 0.0;
float energy_mWh = 0.0, oldegy = 0.0;
unsigned long elapsed = 0;

void setup() {
    // Disable ADC to save power
    ADCSRA = 0;
    ACSR = 0x80;
    
    // Initialize INA219 sensor
    ina219.begin();
    
    // Initialize OLED display
    display.begin(&Adafruit128x64, 0x3C, OLED_RESET);
    display.setFont(System5x7);
    display.clear();
    
    // Configure Timer1 for 10Hz sampling rate
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;
    
    OCR1A = 12499; // = 8000000 / (64 * 10) - 1
    TCCR1B |= (1 << WGM12);  // CTC mode
    TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);  // 64 prescaler
    TIMSK1 |= (1 << OCIE1A);  // Enable timer compare interrupt
    
    sei();
    }
void loop() {
    if (triggered) {
        // Read sensor values
        ina219values();
        
        // Log data to file
        writeFile();
        
        // Update display only when values change
        if(loadvoltage != oldvolt){
        displayline(loadvoltage, 0, " V");
        oldvolt = loadvoltage;
        }
        
        if(current_mA != oldcurr){
        displayline(current_mA, 2, " mA");
        oldcurr = current_mA;
        }
        
        if(power_mW != oldpow){
        displayline(power_mW, 4, " mW");
        oldpow = power_mW;
        }
        
        if(energy_mWh != oldegy){
        displayline(energy_mWh, 6, " mWh");
        oldegy = energy_mWh;
        }
        
        triggered = false;
    }
    }

    // Timer interrupt service routine
ISR(TIMER1_COMPA_vect){
    triggered = true;
    }

    // Display function for OLED
void displayline(const float measurement, const uint8_t line_num, const char line_end[]) {
    char floatbuf[16]={0};
    
    dtostrf(measurement, 10, 3, floatbuf);
    strcat(floatbuf, line_end);
    
    display.setCursor(0, line_num);
    display.print(floatbuf);
    }
void ina219values() {
    float shuntvoltage = 0.0;
    float busvoltage = 0.0;
    
    // Turn the INA219 on
    ina219.powerSave(false);
    
    shuntvoltage = ina219.getShuntVoltage_mV();
    busvoltage = ina219.getBusVoltage_V();
    current_mA = ina219.getCurrent_mA();
    elapsed = millis();
    
    // Turn the INA219 off to save power
    ina219.powerSave(true);
    
    loadvoltage = busvoltage + (shuntvoltage / 1000.0);
    power_mW = loadvoltage * current_mA;
    
    // Compute energy consumed (t = elapsed[ms] / 3600[s/h] * 1000[ms/s])
    energy_mWh += power_mW * (elapsed / 3600000.0);
    }

    // Write data to SD card (requires SD card module)
void writeFile() {
    char buf[32], voltbuf[16]={0}, curbuf[16]={0};
    
    dtostrf(loadvoltage, 10, 3, voltbuf);
    dtostrf(current_mA, 10, 3, curbuf);
    
    // Format CSV line: time,voltage,current\n
    sprintf(buf, "%ld,%s,%s\n", elapsed, voltbuf, curbuf);
    
    // Write to file (implementation depends on SD library setup)
    // measurFile.write(buf);
    
    // Sync to SD card periodically
    // if(cycles >= 9) measurFile.sync();
    }