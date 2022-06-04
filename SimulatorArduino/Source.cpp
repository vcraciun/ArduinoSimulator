#include "Librarie.h"

extern map<int, int> configurare_pini;
extern pair<int, int> placa_utilizata;

int T = 6000;
typedef void (*LED_N)();

void setup()
{
    pinMode(8, TIP_OUTPUT);
    pinMode(12, TIP_OUTPUT);
    pinMode(13, TIP_OUTPUT);
    digitalWrite(8, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
}

void Pulse(int pin, int percent, int T)
{
    float _1_ref = T * (percent / 100.0);
    float _passed = (micros() % T) * 1.0;
    if (_passed < _1_ref)
        digitalWrite(pin, HIGH);
    //_delay_us(T * (percent/100.0));
    else
        digitalWrite(pin, LOW);
    //_delay_us(T * ((100-percent)/100.0));
}

void led_8()
{
    if ((millis() / 500) % 2 == 0)
        //digitalWrite(8, LOW);
        Pulse(8, (millis() / 5) % 100, T);
    else
        //digitalWrite(8, HIGH);
        Pulse(8, 100 - (millis() / 5) % 100, T);
}

void led_12()
{
    if ((millis() / 1000) % 2 == 0)
        Pulse(12, (millis() / 10) % 100, T);
    //digitalWrite(12, LOW);
    else
        Pulse(12, 100 - (millis() / 10) % 100, T);
    //digitalWrite(12, HIGH);  
}

void led_13()
{
    if ((millis() / 2000) % 2 == 0)
        Pulse(13, (millis() / 20) % 100, T);
    //digitalWrite(13, LOW);
    else
        //digitalWrite(13, HIGH);  
        Pulse(13, 100 - (millis() / 20) % 100, T);
}

void loop()
{
    int i;
    LED_N f_leds[3] = { led_13, led_12, led_8 };
    for (i = 0; i < 3; i++)
        f_leds[i]();
}

int main()
{
    placa_utilizata = { ARDUINO_UNO, 20 };
    for (int i = 0; i < placa_utilizata.second; i++)
        configurare_pini[i] = TIP_UNDEFINED;

    setup();
    while (true)
        loop();
    return 0;
}
