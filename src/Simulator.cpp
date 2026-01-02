// Implementação do simulador de eventos discretos
// Modelo: fila de um servidor (M/M/1)
// A simulação avança pulando de evento em evento

// ao chegar cliente:
// cria cliente
// coloca na fila
// avisa Statistics

// quando termina atendimento:
// tira cliente da fila
// calcula tempos
// envia dados pra Statistics

#include <iostream>
#include <random>
#include "../include/Simulator.h"

// executa a simulação:
// - inicializa o primeiro evento
// - processa eventos em ordem de tempo
// - coleta estatísticas finais

void Simulator::run() {
    // cria o evento inicial de chegada
    eventQueue.push(Event(EventType::ARRIVAL, 0.0));

    while (!eventQueue.empty()) {
        Event event = eventQueue.top();
        eventQueue.pop();
        
        currentTime = event.getTime();

        if (event.getType() == EventType::ARRIVAL) {
            handleArrival(event);
        } else {
            handleDeparture(event);
        }
    }
    
    // mostra as estatísticas
    stats.print();
}

// processa a chegada de um cliente:
// - agenda a próxima chegada
// - se o servidor estiver livre, inicia atendimento
// - caso contrário, coloca o cliente na fila

void Simulator::handleArrival(const Event& event) {
    std::cout << "Arrival at " << currentTime << "\n";

    // agenda próxima chegada (fixa por enquanto)
    double nextArrivalTime = currentTime +1.0;
    if (nextArrivalTime <= 10.0) {
        eventQueue.push(Event(EventType::ARRIVAL, nextArrivalTime));
    }

    if (!serverBusy) {
        serverBusy = true;

        // cliente atendido imediatamente -> espera = 0
        stats.recordWaitingTime(0.0);

        double serviceTime = generateServiceTime();
        eventQueue.push(Event(EventType::DEPARTURE,
                            currentTime + serviceTime));
    } else {
        waitingQueue.push(currentTime);
    }
}

// processa o término de um atendimento:
// - se houver clientes esperando, inicia o próximo
// - caso contrário, libera o servidor

void Simulator::handleDeparture(const Event& event) {

    // ocorre após uma saída:
    std::cout << "Departure at " << currentTime << "\n";

    // se ainda tiver alguém na fila
    if (!waitingQueue.empty()) {
        double arrivalTime = waitingQueue.front();
        waitingQueue.pop();

        double waitingTime = currentTime - arrivalTime;
        stats.recordWaitingTime(waitingTime);
        
        double serviceTime = generateServiceTime();
        eventQueue.push(Event(EventType::DEPARTURE,
                            currentTime +serviceTime));
    } else {
        serverBusy = false;
    }
}

// gera um tempo de atendimento aleatório
// usando distribuição exponencial

double Simulator::generateServiceTime() {
    // gera números aleatórios
    static std::default_random_engine generator;
    // distribuição exponencial:
    // - simular quanto tempo vai demorar até o cliente terminar o atendimento
    // - acaba rápido
    // - às vezes demora
    // - raramente demora muito
    static std::exponential_distribution<double> distribution(1.0);

    return distribution(generator);
}