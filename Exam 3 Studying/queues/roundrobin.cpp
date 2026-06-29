

struct process{
    string ID;
    int time;
};

void roundRobin(process arr[], int n, int qt) {
    queue<process> q;
    process curP;
    for (int i = 0; i< n; i++) {
        q.push(arr[i]);
    }
    while (!q.empty()) {
        curP = q.front();
        q.pop();
        curP.time = curP.time - qt;
        if (curP.time <= 0)
            cout << curP.ID << " ";
        else 
            q.push(curP);
    }
    cout << endl;
}