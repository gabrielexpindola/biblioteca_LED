#include <Arduino.h>
#include <LED.h>
/*
Neste exemplo simples, o LED começa piscando, e a piscar mais rápido quando o botão é pressionado. 
Quando é pressionado novamente volta a piscar como iniciou.
*/
const uint8_t pinBotaoBoot = 0;

Led LedA(20);

bool modoRapido = false;

void setup()
{
  pinMode(pinBotaoBoot, INPUT_PULLUP);
  LedA.Piscar();
}

void loop()
{
  LedA.update();
  bool estadoAtualBotaoBoot = digitalRead(pinBotaoBoot);
  static bool estadoAnteriorBotaoBoot = HIGH;

  if (estadoAnteriorBotaoBoot && !estadoAtualBotaoBoot)
  {
      modoRapido = !modoRapido;
      LedA.Piscar(modoRapido ? 6 : 1);
  }
    estadoAnteriorBotaoBoot = estadoAtualBotaoBoot;
}
