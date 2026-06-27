// write a recursive function to print odd numbers in a tree

#include <iostream>
using namespace std;

void printOdd(Node* curr) {
    if (curr != 0) {
        printOdd(curr->left);
        if (curr->val % 2 != 0) {
            cout << curr->val;
        }
        printOdd(curr->right);
    }
}



/* write a recursive function to print the balanced factor of a node
BF(number) = height(l) - height(r)

int BF(node* curr) {
    if (curr->left) && (curr == 0) 
        return 0;
    else 
        return (BF(left) - BF(right));
} 


when being asked for a function recursively that spans 
over whole tree, use a traversal and TWEAK it

BST SEARCH (nested if)
*/