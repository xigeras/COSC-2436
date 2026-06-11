#include <iostream>

using namespace std;

struct car{
    int price;
    car *next;
};

class Dealership{
    private:
        car* head;
        car* tail;
    public:
        Dealership();
        void insertCar(int );
        void print();
        //delete all cars with price < 2000
        car* getHead() {
            return head;
        }
        void deleteAllPrice(int &retprice, int target){
            car *curr = head;
            car *prev = 0;
            car* tmp;
            //if (!isempty())
            while (curr->next != nullptr) {
                if (curr->price < target) {
                    if (curr == head) {
                        tmp = curr;
                        cout << tmp->price;
                        head = head->next;
                        delete tmp;
                    } else {
                        tmp = curr;
                        cout << tmp->price;
                        prev->next = tmp->next;
                        delete tmp;
                    }
                }
                prev = curr;
                curr = curr->next;
                
            }
        }
        void deleteAll();


};

int main() {

    return 0;
}


// delete: mark, empty, update pointers, delete tmp


//  --- recursion ---

//          1. repetition
//          2. condition to stop (if cond to stop, value. else, repeat and change smth)
//          3. if we don't stop, we repeat the repetition + change size


/*
int m (int a, int b) {
    if (b == 0) {
        return 0; 
    } else {
        return a + m(a, b - 1);
    }
}
*/


// practice: count iterations

