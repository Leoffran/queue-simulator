#include "../include/Event.h"

// construtor:
// inicializa type e time com o valor dos seus parâmetros
Event::Event(EventType type, double time)
    : type(type), time(time) {}
    // mesma coisa que escrever
    // this->type = type;
    // this->time = time;
    // dentro das chaves

// getters:
// const garante que a função não vai alterar o objeto
EventType Event::getType() const {
    return type;
}

double Event::getTime() const {
    return time;
}

// classe simples usada apenas para transportar
// informações de eventos na simulação