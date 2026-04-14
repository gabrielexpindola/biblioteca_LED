#include <Arduino.h>
#include <LED.h>
/*
Neste exemplo simples, o LED fica piscando.

*/


Led LedA(20);

void setup()
{
  LedA.Piscar();
}

void loop()
{
  LedA.update();
}
