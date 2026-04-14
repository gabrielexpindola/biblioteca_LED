#include <Arduino.h>
#include <LED.h>
/*
Neste exemplo simples, o LED começa a piscar quando o botão boot é apertado.

*/
const uint8_t pinBotaoBoot = 0;

Led LedA(20);


void setup()
{
  pinMode(pinBotaoBoot, INPUT_PULLUP);
}

void loop()
{
  LedA.update();
  bool estadoAtualBotaoBoot = digitalRead(pinBotaoBoot);
  static bool estadoAnteriorBotaoBoot = HIGH;

  if (estadoAnteriorBotaoBoot && !estadoAtualBotaoBoot)
  {
      LedA.Piscar(2);
  }
    estadoAnteriorBotaoBoot = estadoAtualBotaoBoot;
}
