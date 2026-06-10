#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
    point *next;
};

class line{
    private:
        point *head;
    public: 
        line();
        void insertPoint(int x, int y);
        void print();
        bool searchRecursively(point *, int vx);
}

int main() {
    line straight;
    // after you do all that shit..
    //cout << straight.srec(straight.gethead(), 5);
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

/*
bool searchRecursively(car* curr, int number) {
    if (curr == 0){
        return 0;
    }
    else if (curr->price == number) {
        return 1; //YAY 
    } else {
        return searchRecursively(curr->next, number);
    }
}
*/