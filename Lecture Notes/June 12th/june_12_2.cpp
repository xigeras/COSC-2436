#include <iostream>

using namespace std;

struct node{
    int value;
    node *prev;
    node *next;
    node(int val) : value(val), prev(nullptr), next(nullptr){};
};

class DLL{
    private:
        node *head;
        node *tail;
    public: 
        DLL() : head(nullptr), tail(nullptr) {}
        node* getHead(){
            return head;
        }
        void addatbeg(int k) {
            // create
            node* tmp = new node(k);
            // fill
            tmp->next = head;
            //link
            if(head != nullptr) {
                head->prev = tmp;
            }
            head = tmp;
        }
        void deletefrombeg(int &k) {
            if (head == nullptr) return;
             
            // mark
            node* tmp = head;
            // empty
            k = tmp->value;
            //update
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }
            //delete
            delete tmp;
        }
        void printforward() {
            node* curr = head;

            while (curr != nullptr) {
                cout << curr->value << " ";
                curr = curr->next;
            }
            cout << endl;

        }
        void printbackward() {
            if (head == nullptr) {
                return;
            }
            node* curr = head;

            while (curr->next != nullptr) {
                curr = curr->next;
            }
            while (curr != nullptr) {
                cout << curr->value << " ";
                curr = curr->prev;
            }
            cout << endl;
        }
};

int main() {
    int a;
    DLL highway;
    highway.addatbeg(10);
    highway.addatbeg(20);
    highway.addatbeg(30);
    highway.printforward();
    highway.printbackward();
    highway.deletefrombeg(a);
    highway.printforward();
    highway.deletefrombeg(a);
    highway.printforward();
    highway.printbackward();
    highway.deletefrombeg(a);
    highway.printbackward();



    return 0;

}