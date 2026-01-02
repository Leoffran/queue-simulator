#ifndef EVENT_H
#define EVENT_H

// tipo dos eventos da simulação
enum class EventType {
    ARRIVAL,     // chegada de um cliente
    DEPARTURE    // término de atendimento
};

// representa um evento discreto no tempo da simulação
// cada evento ocorre em um instante específico e possui um tipo
class Event {
public:
    // cria um evento com tipo e tempo de ocorrência
    Event(EventType type, double time);
    
    // retorna o tipo do evento
    EventType getType() const;

    // retorna o instante em que o evento ocorre
    double getTime() const;

private:
    EventType type;  // tipo do evento
    double time;     // instante do evento
};

#endif