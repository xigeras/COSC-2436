#include <iostream>
#include <string>

using namespace std;

// read a sentence from the user via keyboard
// fill a linked list of chars

struct node{
    char c;
    node *next;
}

class listChar{
    private:
        node *head;
        node *tail;
    public: 
        listChar() {
            head = nullptr;
            tail = nullptr;
        }
        node *getHead() {
            return head;
        }
        void insertatend(char c);
        void deleteOtherSingly(node *curr);
        void deleteOtherCircular(node *curr);
        void print(node *curr){
            if (curr == nullptr) {
                return 0;
            } else {
                cout << curr->c << endl;
                print(curr->next);
            }
        }
};

int main() {
    int choice = -1;
    listChar mySentence;
    char sent[80];

    while (choice != 5) {
        cout << "\n----- MENU -----" << endl;
        cout << "0 - Enter a sentence." << endl;
        cout << "1 - Insert a linked list at the end." << endl;
        cout << "2 - Delete every other character recursively (singly LL)" << endl;
        cout << "3 - Delete every other character recursively (circular LL)" << endl;
        cout << "4 - Print remaining characters." << endl;
        cout << "5 - Exit." << endl;

        cout << "Enter your choice: ";
        cin >> choice;
    }

    cin.ignore();

    switch(choice){
        case 0: 
            cout << "Enter a sentence: " << endl;
            cin.getline(sent, 80);
            break;
        case 1: 
            cout << "Inserting Linked List..." << endl;
            for (int i = 0; i < sent.length(); i++) {
                mySentence.insertatend(sent[i]);
            }
            break;
        case 2: 
            cout << "Deleting every other character recursively (singly).." << endl;
            mySentence.deleteOtherSingly(mySentence.getHead());
            break;
        case 3: 
            cout << "Deleting every other character recursively (circular).." << endl;
            mySentence.deleteOtherCircular(mySentence.getHead());
            break;
        case 4: 
            cout << "Printing the current characters remaining..." << endl;
            mySentence.print();
            break;
        case 5: 
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
    }

    return 0;
}

// delete every other letter recursively (print rounds)

// 1. using a single LL (head->next == nullptr)
// 2. using a circular LL (head->next == head || head == nullptr)


// make a MENU for the user
// 0 - enter a sentence
// 1 - Insert a LL?
// 2 - delete other recursively as singly LL
// 3 - delete other recursively as circular LL
// 4 - print
// 5 - exit 

// Enter your choice :
//   --> Do you want to continue (Y/N)?