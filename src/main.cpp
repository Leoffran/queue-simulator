// Como compilar e executar pelo terminal (Windows):
//
// 1. Abra o CMD na pasta do projeto
// 2. Compile:
//    g++ src/*.cpp -Iinclude -o simulator
// 3. Execute:
//    simulator
//
// Obs: requer compilador g++ (MinGW ou similar)

#include "../include/Simulator.h"

// coordena o programa:
// cria o simulador
// roda
// imprime resultados

int main() {
    Simulator sim;
    sim.run();
    return 0;
}