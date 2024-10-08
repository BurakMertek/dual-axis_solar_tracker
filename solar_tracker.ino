/*
 * Dual-Axis Solar Tracking System
 * Main control code for Arduino Nano
 * 
 * This code controls two servo motors based on LDR sensor readings
 * to track the sun's position throughout the day.
 */

int topleft;
int topright;
int downleft;
int downright;
int waittime = 1;

void setup() {
    // Initialize servo control pins
    pinMode(9, OUTPUT);   // Horizontal servo
    pinMode(10, OUTPUT); // Vertical servo



    TCCR1A = 0;
    TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
    TCCR1B = 0;
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
    
    
    ICR1 = 40000;

    // Initialize servo positions (center)
    OCR1A = 3000;  // Horizontal servo
    OCR1B = 3600;  // Vertical servo
    }

void loop() {
    // Read analog values from LDR sensors
    topleft = analogRead(A0);
    topright = analogRead(A1);
    downleft = analogRead(A2);
    downright = analogRead(A3);
    
    // Horizontal tracking logic
    if (topleft > topright) {
        OCR1A = OCR1A + 1;
        delay(waittime);
    }
    
    if (downleft > downright) {
        OCR1A = OCR1A + 1;
        delay(waittime);
    }
    
    if (topleft < topright) {
        OCR1A = OCR1A - 1;
        delay(waittime);
    }
    
    if (downleft < downright) {
        OCR1A = OCR1A - 1;
        delay(waittime);
    }
    
    // Horizontal servo limits
    if (OCR1A > 4000) {
        OCR1A = 4000;
    }
    if (OCR1A < 2000) {
        OCR1A = 2000;
    }
    
    // Vertical tracking logic
    if (topleft > downleft) {
        OCR1B = OCR1B - 1;
        delay(waittime);
    }
    
    if (topright > downright) {
        OCR1B = OCR1B - 1;
        delay(waittime);
    }
    
    if (topleft < downleft) {
        OCR1B = OCR1B + 1;
        delay(waittime);
    }
    
    if (topright < downright) {
        OCR1B = OCR1B + 1;
        delay(waittime);
    }
    
    // Vertical servo limits
    if (OCR1B > 4200) {
        OCR1B = 4200;
    }
    if (OCR1B < 3000) {
        OCR1B = 3000;
    }
    }


