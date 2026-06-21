#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    private:
        Node* tail;
        Node* head;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}
        void pushBack(int val) {
            Node* newNode = new Node(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }
        void print() {
            Node* curr = head;
            cout << "[";
            while (curr != nullptr) {
                cout << curr->data;
                if (curr->next != nullptr) {
                    cout << ",";
                }
                curr = curr->next;
            }
            cout << "]";
        }
        void selectionSort() {
            if (head == nullptr || head->next == nullptr) return;

            Node* curr = head;
            while (curr != nullptr && curr->next != nullptr) {
                Node* min = curr;

                Node* search = curr->next;
                while (search != nullptr) {
                    if (search->data < min->data) {
                        min = search;
                    }
                    search = search->next;
                }

                Node* tmp = curr->next;

                if (min != curr) {
                    if (curr->next == min) {
                        tmp = curr;
                    }

                    Node* prev1 = curr->prev;
                    Node* next1 = curr->next;
                    Node* prev2 = min->prev;
                    Node* next2 = min->next;

                    if (curr->next == min) {
                        curr->next = next2;
                        curr->prev = min;
                        min->next = curr;
                        min->prev = prev1;

                        if (prev1 != nullptr) prev1->next = min;
                        if (next2 != nullptr) next2->prev = curr;
                    } else {
                        curr->next = next2;
                        curr->prev = prev2;
                        min->next = next1;
                        min->prev = prev1;

                        if (prev1 != nullptr) prev1->next = min;
                        if (next1 != nullptr) next1->prev = min;
                        if (prev2 != nullptr) prev2->next = curr;
                        if (next2 != nullptr) next2->prev = curr;
                    }

                    if (head == curr) head = min;
                    else if (head == min) head = curr;

                    if (tail == curr) tail = min;
                    else if (tail == min) tail = curr;

                    curr = min;
                }
                print();
                cout << endl;

                curr = tmp;
            }
        }
        void insertionSort() { 
            if (head == nullptr || head->next == nullptr) {
                return;
            }

            Node* curr = head->next;
            while (curr != nullptr) {
                Node* tmp = curr->next;

                if (curr->data < curr->prev->data) {
                    Node* search = curr->prev;

                    while (search != nullptr && search->data > curr->data) {
                        search = search->prev;
                    }

                    if (curr->prev != nullptr) curr->prev->next = curr->next;
                    if (curr->next != nullptr) curr->next->prev = curr->prev;
                    else tail = curr->prev;

                    if (search == nullptr) {
                        curr->next = head;
                        curr->prev = nullptr;
                        if (head != nullptr) head->prev = curr;
                        head = curr;
                    } else {
                        curr->next = search->next;
                        curr->prev = search;
                        if (search->next != nullptr) search->next->prev = curr;
                        else tail = curr;
                        search->next = curr;
                    }
                }

                print();
                cout << endl;
                curr = tmp;
            }
        }
};

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    string firstLine, secondLine;

    if (!getline(input, firstLine) || !getline(input, secondLine)) {
        cout << "Input is invalid.";
        cout.rdbuf(coutbuf);
        return 0;
    }

    DoublyLinkedList list;
    stringstream ss(firstLine);
    int num;
    bool hasNum = false;

    while (ss >> num) {
        list.pushBack(num);
        hasNum = true;
    }

    if (!hasNum || secondLine.empty()) {
        cout << "Input is invalid.";
        cout.rdbuf(coutbuf);
        return 0;
    }

    if (secondLine == "Selection") {
        list.selectionSort();
    } else if (secondLine == "Insertion") {
        list.insertionSort();
    } else {
        cout << "Input is invalid.";
    }

    cout.rdbuf(coutbuf);
    return 0;
    
}