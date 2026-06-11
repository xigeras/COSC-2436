#include <iostream>

using namespace std;


// argc = argument count. argv = argument vector
int main(int argc, char* argv[]){
    cout << "Hello, world!" << endl;
    cout << argc << endl; // # of arguments

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }


    return 0;
}