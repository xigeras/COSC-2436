#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Process{
    string id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
};

void roundRobin(vector<Process>& processes, int quantum) {
    queue<int> q;
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();

    q.push(0);
    int nextProcess = 1;

    while (completed < n) {
        if (q.empty()) {
            currentTime = processes[nextProcess].arrivalTime;
            q.push(nextProcess++);
            continue;
        }

        int i = q.front();
        q.pop();

        int timeSpent = min(processes[i].remainingTime, quantum);
        currentTime += timeSpent;
        processes[i].remainingTime -= timeSpent;

        while (nextProcess < n && processes[nextProcess].arrivalTime <= currentTime) {
            q.push(nextProcess);
            nextProcess++;
        }

        if (processes[i].remainingTime > 0) {
            q.push(i);
        } else {
            processes[i].completionTime = currentTime;
            completed++;

            int turnaround = processes[i].completionTime - processes[i].arrivalTime;
            cout << processes[i].id << " finished at " << currentTime << " (Turnaround: " << turnaround << ")\n";
        }
    }
}