#include <iostream>

using namespace std;


int main() {

    int *myDynamicArray;
    myDynamicArray = new int[3];
    myDynamicArray[0] = 100;
    myDynamicArray[1] = 200;
    myDynamicArray[2] = 300;

    for (int i = 0; i < 3; i++) {
        cout << myDynamicArray[i] << endl;
    }

    delete[] myDynamicArray;
    
    myDynamicArray = new int[5];
    myDynamicArray[0] = 10;
    myDynamicArray[1] = 20;
    myDynamicArray[2] = 30;
    myDynamicArray[3] = 40;
    myDynamicArray[4] = 50;

    return 0;
}