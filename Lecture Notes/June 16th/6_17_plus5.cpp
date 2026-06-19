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
