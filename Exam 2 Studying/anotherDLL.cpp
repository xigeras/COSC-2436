#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DLL {
    private:
        Node* tail;
        Node* head;
    public:
        DLL() : head(nullptr), tail(nullptr) {}
        ~DLL() {
            Node* curr = head;
            while (curr != nullptr) {
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }
        void printForward() const {
            Node* curr = head;
            while (curr != nullptr) {
                cour << curr->data;
                if (curr->next) cout << " <-> ";
                curr = curr->next;
            }
            cout << endl;
        }
        void printBackward() const {
            Node* curr = tail;
            while (curr != nullptr) {
                cout << curr->data;
                if (curr->prev) cout << " <-> ";
                curr = curr->prev;
            }
            cout << endl;
        }
        void pushFront(int val) {
            Node* newNode = new Node(val);

            if (head == nullptr) {
                head = tail = newNode;
                return;
            }

            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        void pushBack(int val) {
            Node* newNode = new Node(val);

            if (tail == nullptr) {
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        bool remove(int target) {
            Node* curr = head;
            while (curr != nullptr && curr->data != target) {
                curr = curr->next;
            }

            if (curr == nullptr) return false;

            if (curr == head) {
                head = head->next;
                if (head) head->prev = nullptr;
                else tail = nullptr;
                delete curr;
                return true;
            }

            if (curr == tail) {
                tail = tail->prev;
                tail->next = nullptr;
                delete curr;
                return true;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            return true;
        }
}
