#include <iostream>

using namespace std;

struct st{
    int id;
    float gpa;
    st *next;
};

int main(){
    st John; // static allocation
    John.id = 123;
    John.gpa = 3.7;
    John.next = nullptr;

    // dynamic
    st *p = new st;
    st *head = p;

    // TO DO: Write a for loop to 
// 1. create 10 students

    for (int i = 0; i < 10; i++) {
        p->id = rand()%100;
        p->gpa = 1 + rand()%4;
        p->next = 0;
        
        p = p->next;
        p = new st;
    }

    p->id = 999;
    p->gpa = 0;
    p->next = nullptr;

// 2. avg gpa
    p = head;

    for (int i = 0; i < 10; i++) {
        int avg =+ p->gpa;
        p = p->next;
    }

// 3. delete all students
    // mark
    
    st *temp = head;
    // empty
    cout << temp->id << temp->gpa;
    // update pointers
    head = temp->next;
    
    delete temp;
    




    /*
    p->id = 23; //p*.id=23;
    p->gpa = 4.0;
    p->next = 0;

    //second
    p->next = new st;
    p = p->next; //renaming
    p->id = 34;
    p->gpa = 3.0;
    p->next = 0;

    //third 
    p->next = new st;
    p = p->next;
    p->id = 44;
    p->gpa = 2.0;
    p->next = 0;
    */


    return 0;
}



// DELETING:
// 1-mark
// 2-empty
// 3-update pointers
// 4-delete temp

// ADDING:
// 1-create
// 2-fill
// 3-link




