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
        int countCars(car *curr) {
            if (curr == 0) {
                return 0;
            } else {
                return 1 + countCars(curr->next);
            }
        }



};

// count the number of nodes in a linked list recursively

// member or non member function. needs argument (head)


int main() {
    Dealership rizk;
    cout << rizk.countCars(rizk.getHead());
    cout << countCars(rizk.getHead());
    
    return 0;
}