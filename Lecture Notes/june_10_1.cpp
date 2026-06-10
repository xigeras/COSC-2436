#include <iostream>

using namespace std;

struct car{
    int price;
    car *next;
};

class Dealership{
    private:
        car* head;
    public:
        //delete all cars with price < 2000
        car* getHead() {
            return head;
        }
        void deleteAllPrice(int &retprice, int target){
            car *curr = head;
            car *prev = 0;
            car* tmp;
            while (curr->next != nullptr) {
                if (curr->price < target) {
                    tmp = curr;
                    cout << tmp->price;
                    prev->next = tmp->next;
                    delete tmp;
                }
            }
        }
        void deleteAll();


};

int main() {

    return 0;
}


// delete: mark, empty, update pointers, delete tmp