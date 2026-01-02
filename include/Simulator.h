// Responsável por:
// controlar o tempo da simulação
// decidir o próximo evento
// gerenciar fila
// chamar estatísticas

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <queue>
#include <vector>
#include "Event.h"
#include "Statistics.h"

// comparador para priority_queue (menor tempo primeiro)
struct EventCompare {
    bool operator()(const Event& a, const Event& b) const {
        return a.getTime() > b.getTime();
    }
};

class Simulator {
public:
    // roda a simulação
    void run();

private:
    // relógio da simulação
    double currentTime = 0.0;
    // indica se o servidor está atendendo alguém
    bool serverBusy = false;

    // fila de eventos (ordenada por tempo)
    std::priority_queue<Event, std::vector<Event>, EventCompare> eventQueue;
    // fila de clientes (guarda o tempo de chegada)
    std::queue<double> waitingQueue;

    // coleta métricas da simulação
    Statistics stats;

    // processa um evento de chegada:
    // - agenda a próxima chegada
    // - decide se o cliente entra em atendimento ou na fila
    void handleArrival(const Event& event);

    // processa um evento de saída:
    // - finaliza um atendimento
    // inicia o próximo, se houver alguém esperando
    void handleDeparture(const Event& event);

    // gera um tempo de atendimento aleatório
    double generateServiceTime();
};

#endif