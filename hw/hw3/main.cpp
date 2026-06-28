#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class HashTable{
    private:
        int* table;
        int size;
        string type;
    public:
        HashTable(int s, string t) : size(s), type(t) {
            table = new int[size];
            for (int i = 0; i < size; i++) {
                table[i] = -1;
            }
        }
        ~HashTable() { delete[] table; }
        bool search(int val) {
            for (int i = 0; i < size; i++) {
                if (table[i] == val) {
                    return true;
                }
            }
            return false;
        }
        void insert(int val) {
            if (search(val)) return;

            int start = val % size;
            for (int i = 0; i < size * 5; i++) {
                int current = 0;

                if (type == "Linear probing") {
                    int c1 = 1;
                    current = (start + (c1 * i)) % size; 
                } else if (type == "Quadratic probing") {
                    int c1 = 3;
                    int c2 = 5;
                    current = (start + (c1 * i + c2 * i * i)) % size;
                }

                if (table[current] == -1) {
                    table[current] = val; 
                    break; 
                }
            }
        }
        void printTable() {
            bool first = true;
            for (int i = 0 ; i < size; i++) {
                if (table[i] != -1) {
                    if (!first) cout << ",";
                    cout << table[i];
                    first = false;
                }
            }
            cout << endl;
        }
        void buildHeap() {
            int* heap = new int[size];
            int heapSize = 0;

            for (int i = 0; i < size; i++) {
                if (table[i] != -1) {
                    int current = heapSize;
                    heap[current] = table[i];

                    while (current > 0) {
                        int parent = (current - 1) / 2;
                        if (heap[parent] > heap[current]) {
                            swap(heap[parent], heap[current]);
                            current = parent;
                        } else {
                            break;
                        }
                    }
                    heapSize++;
                }
            }

            for (int i = 0; i < heapSize; i++) {
                cout << heap[i] << (i == heapSize - 1 ? "" : ",");
            }
            cout << endl;
            delete[] heap;
        }
};

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    if (!input.is_open()) return -1;

    string size, type, arr, item;
    getline(input, size);
    getline(input, type);
    getline(input, arr);

    if (!type.empty() && type.back() == '\r') type.pop_back();

    HashTable hash(stoi(size), type);
    stringstream ss(arr);

    while (getline(ss, item, ',')) {
        if (!item.empty() && item.back() == '\r') item.pop_back();
        if (!item.empty()) hash.insert(stoi(item));
    }

    hash.printTable();
    hash.buildHeap();

    cout.rdbuf(coutbuf);

    return 0;
}