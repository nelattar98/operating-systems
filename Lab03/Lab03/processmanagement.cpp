

#include <iostream>
#include<iomanip>
#include "Process.h"
using namespace std;
void FCFS(Process*, int, Process*);
void Priority(Process*, int, Process*);
void SJN(Process*, int, Process*);
int main() {
    int processNum;
    int aTime;
    int priority;
    int execTime;
    double averageTT = 0;
    string name = "Job ";
    cout << "How many processes will you have?" << endl;
    cin >> processNum;
    Process* order = new Process[processNum];
    Process * p = new Process [processNum];
    for (int i = 0; i< processNum ; i++){
        cout << "What is the arrival time (ms) of process " << i + 1 << "?" << endl;
        cin >> aTime;
        cout << "What is the priority of process " << i + 1 << "?" << endl;
        cin >> priority;
        cout << "What is the execution time of process " << i + 1 << "?" << endl;
        cin >> execTime;
      
        p[i].setName(i + 1);
        p[i].setArrivalTime(aTime);
        p[i].setPriority(priority);
        p[i].setExecTime(execTime);
    }
    cout << "FCFS: \n";
    
    FCFS(p, processNum, order);
    cout <<"Order " << setw(22) << "Start Time" << setw(17) << "Completion Time" << setw(17) << "Turnaround Time" << endl;
    for(int i = 0; i < processNum; i++){
        averageTT += p[i].getTaTime();
    }
    averageTT /= 1.0 * processNum ;
    for(int i = 0; i < processNum; i++){
        cout << "Process " << order[i].getName() << setw(15) << order[i].getStartTime() << setw(15)<< order[i].getCompletionTime() << setw(15) << order[i].getTaTime() << endl;
    }
    cout << "Average Turnaround Time: " << averageTT << endl;
    cout << "\nPriority: \n";
    Priority(p, processNum, order);
    cout <<"Order " << setw(22) << "Start Time" << setw(17) << "Completion Time" << setw(17) << "Turnaround Time" << endl;
    averageTT = 0;
    for(int i = 0; i < processNum; i++){
        averageTT += p[i].getTaTime();
    }
    averageTT /= 1.0 * processNum ;
    for(int i = 0; i < processNum; i++){
        cout << "Process " << order[i].getName() << setw(15) << order[i].getStartTime() << setw(15)<< order[i].getCompletionTime() << setw(15) << order[i].getTaTime() << endl;
    }
    cout << "Average Turnaround Time: " << averageTT << endl;
    cout << endl;
    cout << "\nShortest Job Next: \n";
    SJN(p, processNum, order);
    cout <<"Order " << setw(22) << "Start Time" << setw(17) << "Completion Time" << setw(17) << "Turnaround Time" << endl;
    averageTT = 0;
    for(int i = 0; i < processNum; i++){
        averageTT += p[i].getTaTime();
    }
    averageTT /= 1.0 * processNum ;
    for(int i = 0; i < processNum; i++){
        cout << "Process " << order[i].getName() << setw(15) << order[i].getStartTime() << setw(15)<< order[i].getCompletionTime() << setw(15) << order[i].getTaTime() << endl;
    }
    cout << "Average Turnaround Time: " << averageTT << endl;
}
void FCFS(Process* p, int n, Process* order){
    int time = 0;
    int count = 0;
    int i = 0;
    /*for(int j = 0; j < n; j++){
        cout << p[j].getPriority() << ' ' << p[j].getExecTime() << ' ' << p[i].getArrivalTime() << ' ' ;
    }*/
    while(i < n){
        if(p[i].getArrivalTime() <= time){
            p[i].setStartTime(time);
            for(int j = 0; j < p[i].getExecTime() ; j++)
                time++;
            p[i].setCompletionTime(time);
            p[i].setTaTime(p[i].getCompletionTime() - p[i].getArrivalTime());
            order[count] = p[i];
            i++;
            count++;
        }
        else
            time++;
    }
}
void Priority(Process* p, int n, Process* order){
    for(int i = 0; i < n; i++){
        p[i].setCompletionTime(-1);
    }
    int i, key, j;
    Process temp;
    int time = 0;
    int count = 0;
    bool jobExecuted =false;
    for (i = 1; i < n; i++)
    {
        key = p[i].getPriority();
        temp = p[i];
        j = i-1;
        
        //sort by priority
        while (j >= 0 && p[j].getPriority() > key)
        {
            p[j+1] = p[j];
            
            j = j-1;
        }
        p[j+1] = temp;
    }
    i = 0;
    while(i < n){
        
        jobExecuted = false;
        for(int j = 0; j< n;j++)
        {
            if(p[j].getArrivalTime() <= time && p[j].getCompletionTime() == -1 ){
                p[j].setStartTime(time);
                time += p[j].getExecTime();
                p[j].setCompletionTime(time);
                p[j].setTaTime(p[j].getCompletionTime() - p[j].getArrivalTime());
                order[count] = p[j];
                i++;
                count++;
                jobExecuted=true;
                break;
            }
        }
        if(jobExecuted==false)
            time++;
    }
}
void SJN(Process* p, int n, Process* order){
    for(int i = 0; i < n; i++){
        p[i].setCompletionTime(-1);
    }
    int i, key, j;
    Process temp;
    int time = 0;
    int count = 0;
    bool jobExecuted =false;
    for (i = 1; i < n; i++)
    {
        key = p[i].getExecTime();
        temp = p[i];
        j = i-1;
        
        //sort by priority
        while (j >= 0 && p[j].getExecTime() > key)
        {
            p[j+1] = p[j];
            
            j = j-1;
        }
        p[j+1] = temp;
    }
    i = 0;
    while(i < n){
        
        jobExecuted = false;
        for(int j = 0; j< n;j++)
        {
            if(p[j].getArrivalTime() <= time && p[j].getCompletionTime() == -1 ){
                p[j].setStartTime(time);
                time += p[j].getExecTime();
                p[j].setCompletionTime(time);
                p[j].setTaTime(p[j].getCompletionTime() - p[j].getArrivalTime());
                order[count] = p[j];
                i++;
                count++;
                jobExecuted=true;
                break;
            }
        }
        if(jobExecuted==false)
            time++;
    }
}
