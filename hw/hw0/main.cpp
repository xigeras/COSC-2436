#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> flipHorizontally(const vector<vector<int>>& originalMatrix);
vector<vector<int>> flipVertically(const vector<vector<int>>& originalMatrix);
vector<vector<int>> rotateRight(const vector<vector<int>>& originalMatrix);

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");

    ifstream inputfile(input);
    ofstream outputfile(output);

    int R, C;
    if (!(inputfile >> R >> C)) return 0;

    vector<vector<int>> matrix(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            inputfile >> matrix[i][j];
        }
    }

    string command;
    while (inputfile >> command) {
        if (command == "FLIP_H") {
            matrix = flipHorizontally(matrix);
        }
        else if (command == "FLIP_V") {
            matrix = flipVertically(matrix);
        }
        else if (command == "ROTATE_R") {
            matrix = rotateRight(matrix);

            int temp_dim = R;
            R = C;
            C = temp_dim;
        }
    }

    int final_R = matrix.size();
    int final_C = matrix[0].size();

    for (int i = 0; i < final_R; i++) {
        for (int j = 0; j < final_C; j++) {
            outputfile << matrix[i][j] << "";
        }
        outputfile << endl;
    }


    inputfile.close();
    outputfile.close();

    return 0;
}

vector<vector<int>> flipHorizontally(const vector<vector<int>>& originalMatrix) {
    int R = originalMatrix.size();
    int C = originalMatrix[0].size();
    vector<vector<int>> temp(R, vector<int>(C));

    // TODO: Iterate through originalMatrix, apply the FLIP_H math, and save to temp
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            int new_R = i;
            int new_C = (C - 1) - j;
            
            temp[new_R][new_C] = originalMatrix[i][j];
        }
    }
    return temp;
}

vector<vector<int>> flipVertically(const vector<vector<int>>& originalMatrix) {
    int R = originalMatrix.size();
    int C = originalMatrix[0].size();
    vector<vector<int>> temp(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int new_R = (R - 1) - i;
            int new_C = j;

            temp[new_R][new_C] = originalMatrix[i][j];
        }
    }

    return temp;
}

vector<vector<int>> rotateRight(const vector<vector<int>>& originalMatrix) {
    int R = originalMatrix.size();
    int C = originalMatrix[0].size();
    vector<vector<int>> temp(C, vector<int>(R));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int new_R = j;
            int new_C = (R - 1) - i;

            temp[new_R][new_C] = originalMatrix[i][j];
        }
    }

    return temp;

}


// research: std::vector, loop that runs x times, and inside that another loop that runs y times