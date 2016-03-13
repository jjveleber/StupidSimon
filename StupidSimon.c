#include <stdint.h>
#include <stdio.h>

#include "Arduino.h"

uint8_t buttonPins[4] = {2, 3, 4, 5};
 
uint8_t getButtonState(uint8_t index) {
    return digitalRead(buttonPins[index]);
}

void setButtonState(uint8_t index) {
    digitalWrite(buttonPins[index], HIGH);
}

void clearButtonState(uint8_t index) {
    digitalWrite(buttonPins[index], LOW);
}

void setup()
{
    // Setup code here
}

void loop()
{
    // Game logic here
    uint8_t i;
    for(i = 0; i < 4; ++i) {
        if(getButtonState(i)) {
            clearButtonState(i);
        } else {
            setButtonState(i);
        }
        
        printf("%09d| Button %d: %s\n", millis(), i, getButtonState(i) ? "Down" : "Up");
		delay(500);
    }
	
}

// This simulates the arduino environment
// Don't edit main as you won't
int main() {
	_initClock();
    setup();
    for(;;) {
        loop();
    }
    return 0;
}
