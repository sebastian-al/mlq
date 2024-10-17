#include "mlq.h"
#include "process.h"
#include <iostream>
#include <fstream>
#include <sstream>

void readFile(const std::string& nameFile, mlq& plan){
    std::ifstream file (nameFile);
    std::string line;
    if(!file.is_open()){
        std::cerr<<"error"<<nameFile<<std::endl;
    }
    while (getline(file, line)){
        if(line[0] == '#')continue;
        std::stringstream ss(line);
        std::string id;
        int burstTime, arrivalTime, queue, priority;
        char delimitador;
        getline(ss, id, ';');
        ss>>burstTime>>delimitador>>arrivalTime>>delimitador>>queue>>delimitador>>priority;
        process p(id, burstTime, arrivalTime, queue, priority);
        plan.addProcess(p);

    }

    file.close();

}
int main(){
    mlq plan; 
    std::string fileName="mlq001.txt";
    readFile (fileName, plan);
    plan.execute();
}