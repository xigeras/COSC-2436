#include <iostream>

using namespace std;

struct Node{

}

int main() {

    return 0;
}


// create a LL recursively of 10 nodes

// functions needed: 
//          - void createrec(int price, int count, car* curr)
//          - 
//          - 

/*
void createrec(int c, car* curr) {
    if (c == 0) {
        return 0;
    } else {
        insertatbeg(curr);
        createrec(c - 1, curr);
    }
}
*/



// some questions:

//          print a LL recursively
//          print a LL recursively backwards


/*
void printRecursively(car* curr) {
    if (curr == nullptr) {
        return 0;
    } else {
        cout << curr->price << endl;
        printRecursively(curr->next);
    }
}
*/

/*
void printBackwards(car *curr) {
    if (curr == nullptr) {
        return 0;
    } else {
        printBackwards(curr->next);
        cout << curr->price << endl;
    }
}
*/