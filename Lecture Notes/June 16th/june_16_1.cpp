#include <iostream>

using namespace std;

class sasa {
    private:
        int *element;
        int top;
    public:
        sasaP{
            element = new id[];
        }
}

// create class SASA
// private: pointer to int, top
//insert and delete functions

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = rand()%100;
    }
    int *b = new int[10];
    for (int i = 0; i < 10; i++) {
        *b = rand()%100;
        b++;
    }

    for (int i = 0; i < 10; i++) {
        cout << a[i] << "\t" << b[i] << endl;
    }

    int *p = &b[0];

    return 0;
}