#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputfile(input);
    ofstream outputfile(output);

    vector<int> R;
    vector<int> C;

    for (int i = 0; i < R; i++) {
        
    }
    

    return 0;
}


// research: std::vector, loop that runs x times, and inside that another loop that runs y times