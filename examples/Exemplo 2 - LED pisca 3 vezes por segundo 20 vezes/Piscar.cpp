#include <Arduino.h>
#include <LED.h>
/*
Neste exemplo simples, o LED pisca 3 vezes por segundo, 20 vezes, depois apaga.

*/


Led LedA(20);

void setup()
{
  LedA.Piscar(3,20);
}

void loop()
{
  LedA.update();
}
