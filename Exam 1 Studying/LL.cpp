#include <iostream>

using namespace std;


struct node{
    int val;
    node* next;
    node* prev;
};

class LinkedList{
    private:
        node* head;
        node* tail;
    public: 
        LinkedList();
        getValueAtIndex(int pos) {
            if (!head)
                return -1;
            
            node* current = head;
            for(int i = 0; current && i<pos; i++) {
                current = current->next;
            } 

            if (!current)
                return -1;
            return current->val;
        }
        addAtPos(node*& head, node* toAdd, int pos) {
            if (!head) { 
                head = nodeToAdd; 
                return;
            }
            node* current = head;
            for (int i = 0; i < pos - 1 && current; i++) {
                current = current->next;
            }

            if (!current) { return; }
            node *tmp = current->next;
            current->next; toAdd;
            toAdd->next;
        }
        removeAtPos();
        traverseAndFind();


        // write a function that takes in 2 lists and returns the head of a new list of all unique values
        uniqueVals(node* h1, node* h2) {
            node* newList = nullptr;
            node* newHead = nullptr;
            
            node* c1 = h1;
            while (c1) {
                node* cc2 = h2;
                while (cc2 && cc1->val != cc2->val) 
                    cc2 = cc2->next;

                if (cc2) {
                    c1 = c1->next;
                    continue;
                }
                
                if (!newList) {
                    newList = new node(cc1->val);
                    newHead = newList;
                } else { 
                    newList->next = new node(cc1->val);
                    newList = newList->next;
                }


            }
        }
}

//1. print all the values in a doubly LL forwards and backwards
//2. print all even values in a LL forwards, then odd values backwards (recursion)
//3. create a new list that represents the union of 2 linked lists, no repeat values