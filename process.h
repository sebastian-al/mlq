#ifndef PROCESS_H
#define PROCESS_H
#include <string>

class process{


public:
    std::string id;
    int burstTime;
    int arrivalTime;
    int priority;
    int queue;
    int completionTime;
    int turnAroundTime;
    int responseTime;
    int waitingTime;

    process(std::string id, int burstTime,  int arrivalTime, int queue, int priority) :
        id(id), burstTime(burstTime), arrivalTime(arrivalTime), priority(priority),
        waitingTime(0), turnAroundTime(0), completionTime(0), responseTime(-1)
    {}

};
#endif