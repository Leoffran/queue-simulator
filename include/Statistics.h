#ifndef STATISTICS_H
#define STATISTICS_H

// coleta e calcula métricas de simulação
// mede o tempo médio de espera dos clientes
class Statistics {
public:
    // registra o tempo de espera de um cliente
    // deve ser chamada quando o atendimento se inicia
    void recordWaitingTime(double time);

    // imprime as estatísticas finais da simulação
    void print() const;

private:
    // soma dos tempos de espera
    double totalWaitingTime = 0.0;
    // número de clientes atendidos
    int customerCount = 0;
};

#endif