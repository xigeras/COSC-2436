#include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
 
using namespace std;

struct credential{
    string name;
    int age;
    int deposit;
    int drinks;
    credential* next;
};

class Casino{
    private:
        credential* head;
    public:
        Casino() { head = nullptr; }
        credential* getHead() { return head; }
        credential* searchDuplicates(string targetName, int targetAge) {
            credential* curr = head;

            while (curr != nullptr) {
                if (curr->name == targetName && curr->age == targetAge) {
                    return curr;
                }
                curr = curr->next;
            }
            return nullptr;
        }
        void addatIndex(string name, int age, int deposit, int drinks, int index) {
            credential* duplicate = searchDuplicates(name, age);
            if (duplicate != nullptr) {
                duplicate->deposit = deposit;
                duplicate->drinks = drinks;
                return;
            }

            credential* tmp = new credential(name, age, deposit, drinks);

            if (index == 0 || head == nullptr) {
                tmp->next = head;
                head = tmp;
                return;
            }

            credential* curr = head;
            for (int i = 0; i < index - 1; i++) {
                if (curr->next == nullptr) {
                    break;
                }
                curr = curr->next;
            }

            tmp->next = curr->next;
            curr->next = tmp;
        }
        void removebyAttribute(string attr, string val) {
            while (head != nullptr) {
                bool match = false;
                if (attr == "name" && head->name == val) match = true;
                else if (attr == "age" && to_string(head->age) == val) match = true;
                else if (attr == "deposit" && to_string(head->deposit) == val) match = true;
                else if (attr == "number of drinks" && to_string(head->drinks) == val) match = true;
            
                if (match) {
                    credential* tmp = head;
                    head = head->next;
                    delete tmp;
                } else {
                    break;
                }
            }

            if (head == nullptr) { return; }

            credential* curr = head;
            while (curr->next != nullptr) {
                bool match = false;
                if (attr == "name" && curr->next->name == val) match = true;
                else if (attr == "age" && to_string(curr->next->age) == val) match = true;
                else if (attr == "deposit" && to_string(curr->next->deposit) == val) match = true;
                else if (attr == "number of drinks" && to_string(curr->next->drinks) == val) match = true;
            
                if (match) {
                    credential* tmp = curr->next;
                    curr->next = curr->next->next;
                    delete tmp;
                } else {
                    curr = curr->next;
                }
            }
        }
        void sortList(string attr) {
            if (head == nullptr || head->next == nullptr) return;

            bool swapped;
            do {
                swapped = false;
                credential* curr = head;

                while (curr->next != nullptr) {
                    bool shouldSwap = false;

                    if(attr == "name") {
                        if (curr->name > curr->next->name) shouldSwap = true;
                    } else if (attr == "age") {
                        if (curr->age > curr->next->age) shouldSwap = true;
                    } else if (attr == "deposit") {
                        if (curr->deposit > curr->next->deposit) shouldSwap = true;
                    } else if (attr == "number of drinks") {
                        if (curr->drinks > curr->next->drinks) shouldSwap = true;
                    }

                    if (shouldSwap) {
                        swap(curr->name, curr->next->name);
                        swap(curr->age, curr->next->age);
                        swap(curr->deposit, curr->next->deposit);
                        swap(curr->drinks, curr->next->drinks);
                        swapped = true;
                    }
                    curr = curr->next;
                }
            } while(swapped);
        }

        void printList(ofstream& out) {
            credential* curr = head;
            while (curr != nullptr) {
                out << "[name: " << curr->name << "; age: " << curr->age
                    << "; deposit: " << curr->deposit << "; number of drinks: "
                    << curr->drinks << "]" << endl;
                curr = curr->next;
            }
        }
};

void parseString(string line, string& name, int& age, int& deposit, int& drinks) {
    int p1 = line.find("name: ") + 6;
    int p2 = line.find("; age: ");
    name = line.substr(p1, p2 - p1);

    int p3 = p2 + 7;
    int p4 = line.find("; deposit: ");
    age = stoi(line.substr(p3, p4 - p3));

    int p5 = p4 + 11;
    int p6 = line.find("; number of drinks: ");
    deposit = stoi(line.substr(p5, p6 - p5)); 

    int p7 = p6 + 20;
    int p8 = line.find("]");
    drinks = stoi(line.substr(p7, p8 - p7));
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input")), cmd(am.get("command"));
    ofstream output(am.get("output"));

    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(output.rdbuf());
    
    Casino db;

    string line, name;
    int age, deposit, drinks;

    while (getline(input, line)) {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        
        if (line.empty()) continue;

        parseString(line, name, age, deposit, drinks);
        db.addatIndex(name, age, deposit, drinks, 999999);
    }

    while (getline(cmd, line)) {
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());

        if (line.empty()) continue;

        if (line.find("Add") != string::npos) {
            int n = stoi(line.substr(line.find("(") + 1, line.find(")") - line.find("(") - 1));
            parseString(line, name, age, deposit, drinks);
            db.addatIndex(name, age, deposit, drinks, n);
        } else if (line.find("Remove") != string::npos) {
            string attr = line.substr(line.find("[") + 1, line.find(":") - line.find("[") - 1);
            string val = line.substr(line.find(": ") + 2, line.find("]") - line.find(": ") - 2);
            db.removebyAttribute(attr, val);
        } else if (line.find("Sort") != string::npos) {
            string attr = line.substr(line.find("(") + 1, line.find(")") - line.find("(") - 1);
            db.sortList(attr);
        }
    }

    db.printList(output);
    return 0;
}