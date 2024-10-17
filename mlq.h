#ifndef MLQ_H
#define MLQ_H
#include <vector>
#include "queue.h"

class mlq{


public:
    std::vector<queue> cola;
    mlq();
    void addProcess(const process& p);
    void execute();

private:
    void roundRobin(queue &queue);
    void executeFcfs(queue &queue);

   
};
#endif