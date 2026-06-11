// Print your name 10 times

// 1. How long does it take to run this code?
    // 10 units of time to print 10 times
    // printing n names takes n times
    // execution time is LINEAR! So it's O(n)
    // code cant go too fast. cant go exponential. very bad
    // if our code is constant (no growth), best!
    // though linear is the PREFERRED execution time b/c it grows slowly
// 2. How many spaces/bytes will this code take? (space complexity)

//Write myName


// Write a program to print all class names

/* O(5)! but actually this is simplified to O(1)
int a;
int a - 10;
cout << a;
a += 7
cout << a;
*/


/*
int n = 100;                         1
for (int i = 0; i < n; i++) {        3       1+3 = 4, n + 4. Simplified to O(n)
    cout << i;                       n
}
*/



/*
for (int i = 0; i < 10; i++) {        -> 3
    for (int j = 0; j < 10; j)) {     -> 3
                                    <------- n * k sooo O(n^2)!
    }}
*/


// What is Big O? (growth of your execution time should be as slow as possible)
//        Best case scenario: O(1). Any input we have a constant time.
// What is upper/lower bounds? 
// How to count the statements (aka determining time complexity from some code)
// What are the best / worse / average cases?





/*
cin >> n                              it is n + 3, but if a user 
for (int i = 0; i < n; i++) {         writes 0 for n, big O would be
    cout << n;                        O(1).
}
*/


// BEST / WORSE/ AVERAGE CASES! 

/*
O(log n) 
*/

// Sort complexity by time growth. Which one is the best? 




/*
====== Linear Search ======

Best case if key is found at first location, O(1)
worst case if its found at the last index O(n)

Average case = all cases / # of cases
             = key can be anywhere n / n
             = total # of comparisons 1+2+..../n
             = n(n+1) / 2 / n
             = (n+1)/2 ----> O(n)
*/







/* 
===== BINARY TREES =====

while (cond 1 || cond 2) {
}

if ( C1) 
    return true;
else
    false;


if (C2) 
    return false;
else
    true;
*/


/*
[7, 10, 15, 22, 40, 75] looking for 75!

m = 0 + 5 / 2 = 2

75 > 15? yes


m = 3 + 5 / 2 = 4

40 > 75? yes

75

*/




/*
==== SORTING ====

[5, 1, 3, 2, 4] Bubble Sort
[1, 5, 3, 2, 4] Pass 1
[1, 3, 5, 2, 4]
[1, 3, 2, 5, 4]
[1, 3, 2, 4, 5]

[1, 3, 2, 4, 5] Pass 2
[1, 2, 3, 4, 5]

[1, 2, 3, 4, 5] Pass 3 (just checking at this point tbh)

[1, 2, 3, 4, 5] Pass 4 
sorted! 

What is Big O of Bubble Sort?

(n-1) passes, each pass we have n. time complexity is O(n^2)
Best case: O(n^2)
Worst case:  5 4 3 2 1... O(n^2)
Average case: 
*/