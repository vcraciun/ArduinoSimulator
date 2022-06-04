#include "Librarie.h"

map<int, int> configurare_pini;
pair<int, int> placa_utilizata;

void pinMode(int pin, int tip_pin)
{
	//Atentie! trebuie verificat ca pinul exista - Exceptie
	configurare_pini[pin] = tip_pin;
}

void digitalWrite(int pin, int semnal_iesire)
{
	static map<int, pair<SHORT, SHORT>> pozitii;
	static int y = 0;

	//Atentie! trebuie verificat ca pinul exista si ca este OUTPUT - Exceptie
	if (pozitii.find(pin) == pozitii.end())
	{
		pozitii[pin] = { 0, y };
		y += 1;
	}

	HANDLE stdo = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(stdo, { pozitii[pin].first, pozitii[pin].second});
	printf("\r                                      ");
	printf("\rLED(%d): %d", pin, semnal_iesire);
}

long long millis()
{
	long long millis;
	SYSTEMTIME timp;
	GetLocalTime(&timp);
	millis = timp.wMilliseconds + timp.wSecond * 1000 + timp.wMinute * 60 * 1000 + timp.wHour * 3600 * 1000 + timp.wDay * 24 * 3600 * 1000;
	Sleep(50);
	return millis;
}

long long micros()
{
	FILETIME ft;
	long long micros;

	GetSystemTimePreciseAsFileTime(&ft);
	micros = ft.dwHighDateTime;
	micros <<= 32;
	micros |= ft.dwLowDateTime;
	Sleep(50);
	return micros;
}

