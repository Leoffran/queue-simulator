#include <iostream>
#include "../include/Statistics.h"

// registra o tempo de espera de um cliente
// deve ser chamado quando o atendimento começa
void Statistics::recordWaitingTime(double time) {
    totalWaitingTime += time;
    customerCount++;
}

// imprime métricas finais da simulação
void Statistics::print() const {
    // evita divisão por zero
    if (customerCount == 0) {
        std::cout << "No customers served.\n";
        return;
    }

    double averageWaitingTime = totalWaitingTime / customerCount;
    std::cout << "Customers served: " << customerCount << "\n";
    std::cout << "Average waiting time: " << averageWaitingTime << "\n";
}