#pragma once
#include <stdio.h>
#include <iostream>
#include <map>
#include <windows.h>
using namespace std;

enum tipuri_pin {
	TIP_INPUT,
	TIP_OUTPUT,
	TIP_UNDEFINED
};

enum semnale_iesire {
	LOW,
	HIGH
};

enum placi_dezvoltare {
	ARDUINO_UNO,
	MEGA2560,
	LEONARDO,
	NANO
};

void pinMode(int pin, int tip_pin);
void digitalWrite(int pin, int semnal_iesire);
long long millis();
long long micros();

