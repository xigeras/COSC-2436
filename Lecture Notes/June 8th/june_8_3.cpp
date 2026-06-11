#include <iostream>

using namespace std;

int main(){
    int *p = new int[5];
    for(int i = 0; i < 5; i++){
        //cout << p[i] << endl;
        p[i] = rand() % 100;
    }
    for (int i = 0; i < 5; i++) {
        cout << *p << endl;
        p++;
    }

    return 0;
}