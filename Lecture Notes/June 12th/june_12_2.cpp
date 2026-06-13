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
        DLL();
        void addatbeg(int k) {

        }
        void deletefrombeg(int &k);
        void printforward();
        void printbackward();
}

int main() {
    dll highway;
    

    return 0;

}