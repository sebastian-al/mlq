#include "mlq.h"
#include "process.h"
#include "queue.h"
#include <iostream>

mlq::mlq(){
    cola.push_back(queue("RR",1));
    cola.push_back(queue("RR",3));
    cola.push_back(queue("FCFS"));

}

void mlq::addProcess(const process& p){
    cola[p.queue-1].proc.push(p);
}

void mlq::execute(){
    for(auto &queue : cola){
        if (queue.planificacion=="RR"){
            roundRobin(queue);
        } else if(queue.planificacion=="FCFS"){
            executeFcfs(queue);
        }
    }
}

void mlq::roundRobin(queue &queue){
    std::queue<process> tempQueue;
    int quantum=queue.quantum;
    int currentTime=0;
    while(!queue.proc.empty())
    {
        process process=queue.proc.front();
        queue.proc.pop();
        
        if(process.responseTime==-1)
        {
            process.responseTime==currentTime-process.arrivalTime;

        }

        int timeToExecute=std::min(quantum, process.burstTime);
        process.burstTime -=timeToExecute;
        currentTime+=timeToExecute;

        if(process.burstTime>0){
            tempQueue.push(process);

        }else{
            process.completionTime=currentTime;
            process.turnAroundTime=process.completionTime-process.arrivalTime;
            process.waitingTime=process.turnAroundTime-(process.completionTime-process.responseTime);
            std::cout<<"proceso"<<process.id<<"completado en "<<currentTime<<std::endl;

        }
    } 

    queue.proc=tempQueue;

    

}

void mlq::executeFcfs(queue &queue){
    int currentTime=0;
    while (!queue.proc.empty()){
        process process=queue.proc.front();
        queue.proc.pop();

        if(currentTime<process.arrivalTime){
            currentTime=process.arrivalTime;
        }

        process.responseTime=currentTime-process.arrivalTime;
        process.completionTime=currentTime+process.burstTime;
        process.turnAroundTime=process.completionTime-process.arrivalTime;
        process.waitingTime=process.turnAroundTime-process.burstTime;
        currentTime=process.completionTime;
        std::cout<<"proceso"<<process.id<<"completado en "<<currentTime<<std::endl;

    }

    

    
}