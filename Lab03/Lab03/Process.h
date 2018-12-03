
#include<iostream>
#include<string>
using namespace std;
#ifndef LAB02_H
#define LAB02_H
class Process{
    int execTime;
    int arrivalTime;
    int priority;
    int completionTime;
    int name;
    int startTime;
    int TaTime;
public:
    Process() {execTime = -1; arrivalTime = -1; priority = -1; completionTime = -1; name = -1; startTime = -1;}
    const int getExecTime() const{return execTime;}
    void setExecTime(int e) {execTime = e;}
    int getArrivalTime() const {return arrivalTime;}
    void setArrivalTime(int a) {arrivalTime = a;}
    int getPriority() const {return priority;}
    void setPriority(int p) {priority = p;}
    int getCompletionTime() const {return completionTime;}
    void setCompletionTime(int c) {completionTime = c;}
    int getName()const {return name;}
    void setName(int n){name = n;}
    int getStartTime() const{return startTime;}
    void setStartTime(int s) {startTime = s;}
    int getTaTime() const{return TaTime;}
    void setTaTime(int t){TaTime = t;}
    Process& operator= (const Process& rhs){
        this->execTime = rhs.getExecTime();
        this->arrivalTime = rhs.getArrivalTime();
        this->priority = rhs.getPriority();
        this->completionTime = rhs.getCompletionTime();
        this->name = rhs.getName();
        this->startTime = rhs.getStartTime();
        this->TaTime = rhs.getTaTime();
        return *this;
    }
};
#endif
