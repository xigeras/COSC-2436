#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
    int *p = new int;
    cout << p << endl;
    *p = 10;
    (*p)++;
    cout << *p << endl;
    cout << p << endl;

    delete p;

    p = nullptr; //p = 0
    p = new int[5];
    cout << p << endl;
    int *head = p;
    

    for (int i = 0; i < 5; i++){
        *p = i*10;
        cout << "inside loop p is..." << p << endl;
        p++;
    }

    p -= 4; 
    p = head;
    cout << "-----------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << p[i] << endl;
    }
    return 0;
}