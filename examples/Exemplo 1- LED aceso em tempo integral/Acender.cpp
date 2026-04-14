#include <Arduino.h>
#include <LED.h>
/*
Neste exemplo simples, o LED fica aceso e não apaga.

*/


Led LedA(20);

void setup()
{
  LedA.Acender();
}

void loop()
{
  LedA.update();
}
