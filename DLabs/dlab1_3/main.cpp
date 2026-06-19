#include <iostream>
#include <cmath>
using namespace std;

void solveHanoi(int disks, int start, int target, int helper) {
    // base case: if disks = 0, stop and return
    if (disks == 0) {
        return;
    }


    //move the top pile of (disks - 1) out of the way
    // go from start to helper
    solveHanoi(disks - 1, start, helper, target);
    

    // move the 1 remaining biggest disk
    // print the move from the start stack to the target stack
    cout << start << " " << target << "\n";

    // move the pile you set aside onto the target
    // go from helper to target
    solveHanoi(disks - 1, helper, target, start);

}

int main() {
    int n;
    cin >> n;

    // calculate and print total # of moves ( 2^n - 1) 
    long long moves = 1;
    for (int i = 0; i < n; i++) {
        moves = moves * 2;
    }
    moves = moves - 1;

    cout << moves << "\n";



    //first call. move 'n' disks from peg 1 to peg 3, and use 
    //peg 2 as helper


    solveHanoi(n, 1, 3, 2);

    return 0;
}