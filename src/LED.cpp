#include "LED.h"

Led::Led(uint8_t Pin) :
    Pino(Pin),
    Estado(LOW),
    apagarNoTempo(false),
    apagarNoMomento(false),
    estadoPiscar(false),
    tempoEspera(0),
    tempoAnteriorPiscar(0),
    repeticoes(0)
{
    pinMode(Pino, OUTPUT);
}

void Led::Acender()
{
    Estado = HIGH;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::Acender(uint32_t tempoLigado)
{
    Estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = millis() + tempoLigado;
    apagarNoTempo = true;
    estadoPiscar = false;
}

void Led::Apagar()
{
    Estado = LOW;
    estadoPiscar = false;
    apagarNoTempo = false;

}

void Led::Alternar()
{
    Estado = !Estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::SetEstado(bool Estado)
{
    this->Estado = Estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

uint8_t Led::GetPino()
{
    return Pino;
}

void Led::update()
{
    if (apagarNoTempo)
        funcaoApagarNoTempo();
    if (estadoPiscar)
        funcaoPiscar();
    digitalWrite(Pino, Estado ? HIGH : LOW);
}

void Led::Piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    Estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::Piscar(float freq)
{
    if(freq == 0)
    {
        return;
    }
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriorPiscar = millis();
    Estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::Piscar(float freq, uint16_t repeticoes)
{
    if(freq == 0)
    {
        return;
    }
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriorPiscar = millis();
    Estado = HIGH;
    this->repeticoes = repeticoes * 2;
    apagarNoTempo = false;
}

void Led::funcaoApagarNoTempo()
{
    if (millis() >= apagarNoMomento)
    {
        Estado = LOW;
        apagarNoTempo = false;
    }
}

void Led::funcaoPiscar()
{

    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        Estado = !Estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                Estado = LOW;
            }
        }
    }
}