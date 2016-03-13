#ifndef ARDUINO_H
#define ARDUINO_H

/*Fake Arduino Code*/
#include <stdint.h>
#include <time.h>
#include <stdio.h>

#define HIGH 0x1
#define LOW  0x0
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

//void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
int digitalRead(uint8_t);
//int analogRead(uint8_t);
//void analogReference(uint8_t mode);
//void analogWrite(uint8_t, int);


uint32_t _pins = 0x0;
struct timespec _start;

void _initClock() {
	clock_gettime(CLOCK_MONOTONIC, &_start);
}

void digitalWrite(uint8_t pin, uint8_t value) {
	int bit = (1 << (pin-1));
	if (value == LOW) {
			_pins &= ~bit;
	} else {
			_pins |= bit;
	}
}

int digitalRead(uint8_t pin) {
	return (_pins & (1 << pin));
}

unsigned long millis() {
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &now);
	return 1000.0*now.tv_sec + 1e-6*now.tv_nsec
                       - (1000.0*_start.tv_sec + 1e-6*_start.tv_nsec);
}

void delay(unsigned long milliSeconds) {
	nanosleep(&(struct timespec){.tv_nsec=(milliSeconds*1000000)}, NULL);
}

#endif /* ARDUINO_H */