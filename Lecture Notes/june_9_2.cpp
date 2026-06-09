#include <iostream>

using namespace std;

struct pearl{
    int size;
    int color;
    pearl *next;
};

class Necklace{
    private:
        pearl *head;
    public: 
        Necklace(){head = 0;}
        pearl* getHead() {
            return head;
        }
        void addAtBeg(int a, int b) {
            //1-create
            pearl *tmp = new pearl;
            //2- fill
            tmp->size = a;
            tmp->color = b;
            tmp->next = 0;
            //3-link
            tmp->next = head;
            head = tmp;
        }
        void deleteFromBeg(int & a, int & b){
            //1-mark
            pearl *tmp = head;
            //2-empty
            a = tmp->size;
            b = tmp->color;
            //3-update pointers
            head = head->next;
            //4
            delete tmp;
        }

        void deleteFromPos(int &a, int &b, int pos) {
            pearl* curr = head;
            for (int i = 0; i < pos-1; i++) {
                curr = curr->next;

                //....start deletefrompos
                //step1
                pearl *tmp = curr->next;

                // 2-empty
                a = tmp->size;
                b = tmp->color;

                //3-update pointers
                curr->next = tmp->next;

                //4 
                delete tmp;
            }
        }
        void deleteFromEnd(int &a, int &b) {
            pearl *curr = head;
            pearl *prev;
            while (curr->next != nullptr) {
                prev = curr;
                curr = curr->next;
            }
            curr = prev;
            // mark
            pearl *tmp = curr->next;
            // empty
            a = tmp->size;
            b = tmp->color;
            //update
            curr->next = nullptr;
            //delete
            delete tmp;
        }

        void addAtPos(int a, int c, int pos) {
            pearl *curr = head;
            pearl *tmp;
            for (int i = 1; i < pos-1; i++) {
                curr = curr->next;
                // create a node outside
                tmp = new pearl;
                tmp->size = a;
                tmp->color = c;
                tmp->next = 0;

                // link
                tmp->next = curr->next;
                curr->next = tmp;

            }
        }
        
        void print() {
            pearl *curr = head;
            while (curr != nullptr) {
                cout << curr->size << endl;
                cout << curr->color << endl;
                curr = curr->next; //why did she do -= here?
            }

        }
        
};

int main() {
    int a, b;
    Necklace birthday;
    birthday.addAtBeg(10, 1);
    birthday.addAtBeg(5, 3);
    birthday.addAtBeg(4, 2);
    birthday.print();
    birthday.deleteFromBeg(a, b);
    cout << "I just deleted a pearl with size " << a << "and color " << b << endl;
    
    return 0;
}



//learn how to do: add pearl at any position

// types of add:
//                    - add at beginning
//                    - add at position (base > value)
//                    - add at end

//types of delete:
//              - delete at beg
//              - delete at pos
//              - delete at end


// put class structure in header file
// try ALL functions.
