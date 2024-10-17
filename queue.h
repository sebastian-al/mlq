#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include "process.h"

class queue{


public:
    std::queue<process> proc;
    std::string planificacion;
    int quantum; 

    queue(std::string planificacion, int quantum=1) :
       planificacion(planificacion), quantum(quantum)
    {}

};
#endif