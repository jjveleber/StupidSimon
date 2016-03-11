#include <stdint.h>
#include <stdio.h>
 
uint8_t buttonStates = 0b00000101;

uint8_t getButtonState(uint8_t index) {
    return (buttonStates & (1 << index));
}

void setButtonState(uint8_t index) {
    buttonStates |= (1 << index);
}

void clearButtonState(uint8_t index) {
    buttonStates &= ~(1 << index);
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
        
        printf("Button %d: %s\n", i, getButtonState(i) ? "Down" : "Up");
    }
}

// This simulates the arduino environment
// Don't edit main as you won't
int main() {
    setup();
    for(;;) {
        loop();
    }
    return 0;
}