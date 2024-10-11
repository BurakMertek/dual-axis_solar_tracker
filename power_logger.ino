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