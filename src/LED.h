#ifndef LED_h

#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar porvquantidade definida.
 * @note O método Update() deve ser chamado continuamente dentro do loop().
 *
 * @param Pin - pino ao qual o LED foi conectado.
 *
 */
class Led
{
private:
    uint8_t Pino;
    bool Estado;
    bool apagarNoTempo;
    uint32_t apagarNoMomento;
    bool estadoPiscar;

    uint32_t tempoEspera;
    uint32_t tempoAnteriorPiscar;
    uint16_t repeticoes;
    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoApagarNoTempo();
    /**
     * @brief Processa a lógica de escada do LED.
     */
    void funcaoPiscar();

public:
    /**
     * @brief Constrói um objeto Led.
     * @param Pin o número do pino digital onde o LED está conectado.
     */
    Led(uint8_t Pin);

    /**
     * @brief Liga o Led continuamente.
     */
    void Acender();

    /**
     * @brief Liga o Led por um tempo determinado
     * @param TempoLigado Tempo, em milissegundos que o Led ficará ligado.
     */
    void Acender(uint32_t TempoLigado);

    /**
     * @brief Desliga o Led e cancela modúlos automáticos.
     */
    void Apagar();

    /**
     * @brief Pisca o LED.
     */
    void Piscar();

    /**
     * @brief Faz o LED piscar em uma certa frequência. 
     * @param Freq Frequência de vezes que o LED irá piscar por segundo em float. 
     */
    void Piscar(float Freq);

    /**
     * @brief Faz o LED piscar em uma certa frequência com limite de repetições. 
     * @param Freq Frequência de vezes que o LED irá piscar por segundo em float. 
     * @param Repeticoes Número de repetições que o LED vai executar. 
     */
    void Piscar(float Freq, uint16_t Repeticoes);


    /**
     * @brief Altera os estados do LED e reseta o tempo e o estado piscar.
     */
    void Alternar(); 

    /**
     * @brief Recebe o Estado do Led.
     * @param Estado Estado que o Led vai receber (true e false)
     */
    void SetEstado(bool Estado); 

    /**
     * @brief Lê o número do pino.
     */
    uint8_t GetPino(); 

    /**
     * @brief Atualiza a funcaoApagarNoTempo() e funcaoPiscar() e escreve o estado do pino. 
     */
    void update();     
};

#endif