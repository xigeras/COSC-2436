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
        void print();
};

int main() {
    int a, b;
    Necklace birthday;
    birthday.addAtBeg(10, 1);
    birthday.addAtBeg(5, 3);
    birthday.addAtBeg(4, 2);
    birthday.print();
    birthday.deleteFromBeg(a, b);
    
    return 0;
}
