#include <iostream>
#include <queue>
using namespace std;

/*
Write the function priorityRoundRobin(lines arr[], int n, int quantumTime) which performs a
round robin scheduling algorithm only on lines that have a 1 in the priority slot. You must use
queues in your implementation. N is the number of processes in the array.

*/

Struct lines{
    int priority;
    int time;
};

void priorityRoundRobin(lines arr[], int n, int quantumTime) {
    queue<lines> q();
    for (int i = 0; i < n; i++) {
        if (lines[i].priority == 1) {
            q.push(i);
        }
        while (!q.empty()) {
            lines curr = q.front();
            if (curr.time > quantumTime) {
                curr.time -= quantumTime;
                q.push(curr);
                q.pop();
            } else {
                q.pop();
            }
        }
    }
}




