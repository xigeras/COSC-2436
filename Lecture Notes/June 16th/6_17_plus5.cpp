/*
simulation of open chaining

1- create a dynamic array of 7 days ( dynamic array of pointers to linked lists)

2- the hash function is to read a date and return a day : Monday tuesday ...use enumerated type to 
return a number between 0 and 6

3- the hashing process : is to map the food generate a random random  (as a number to a different 
list of days )
   monday : 0..10  rand()%10

  tuesday : 11..20  (11+rand()%10)

   wednesday 21..30  (21 +rand()%10)

sugegstation enum fruit { apple 0, orange 1.....}

                       enum veg { cucom 11 

7 days a week turn into array, node ** days = new node*[7] of linked list. 
So 0 maps to Monday 1 to Tuesday so on. Then given date like 6/17 turn that into day of week, 
so Wednesday. Then have enum index of {Monday = 0, Tuesday =1….} then you have struct node and 
class list and make list Monday, Tuesday, etc. then today is Wednesday so check with enum index 
and return 2. Then make switch case if 2 list Wednesday.addatbeg()
Then you make a while loop that generates random numbers. 
Each days has a specific range Monday  < 10 Tuesday 10-20 so on. 
In switch case 2 you have while loop that keeps generating until you have a number in range 20-30. 
All the others numbers generated get added to the correct day of the week. So if you run 
while loop and get 10,23 33, 34. 10 gets added to link list Tuesday , 23 to Wednesday, 
33 to Thursday, and 34 to thursday. 
Then at the end print out all list with a for loop.


*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node{
   int data;
   Node* next;
   Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
   public:
      Node* head;
      LinkedList() : head(nullptr) {}

      void addAtBeg(int val) {
         Node* tmp = new Node(val);
         tmp->next = head;
         head = tmp;
      }
      void print() {
         Node* curr = head;
         while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
         }
         cout << "NULL\n"
      }
};

enum Day { MONDAY = 0, TUESDAY = 1, WEDNESDAY = 2, THURSDAY = 3, FRIDAY = 4, SATURDAY = 5, SUNDAY = 6 };
int main() {
   srand(time(0));

   LinkedList** days = new LinkedList*[7];
   for (int i = 0; i < 7; i++) {
      days[i] = new LinkedList();
   }

   Day targetDay = WEDNESDAY;
   bool targetFound = false;

   while (!targetFound) {
      int randNum = rand() % 70;
      int assignDayIndex = randNum / 10;

      days[assignDayIndex]->addAtBeg(randNum);

      cout << "Generated: " << randNum << " -> Added to Day [" << assignDayIndex << "]\n";

      if (assignDayIndex == targetDay) {
         targetFound = true;
      }
   }

   cout << "\n=== FINAL HASH TABLE ===\n";
   string dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

   for (int i = 0; i < 7; i++) {
      cout << dayNames[i] << " (" << i*10 << "-" >> (i*10)+9 << "): ";
      days[i]->print();
   }

   for (int i = 0; i < 7; i++) {
      delete days[i];
   }
   delete[] days;

   return 0;
}

