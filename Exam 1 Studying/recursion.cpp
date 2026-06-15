#include <iostream>

using namespace std;

long long fib(int n) { //fibonacci sequence
    if (n == 0 || n == 1) {
        return n;
    } else {
        return (fib(n-2) + fib(n-1));
    }
}

string reverse (string str) {
    if (str.length() <= 1) {
        return str;
    } else {
        return reverse(str.substr(1, str.length() - 1)) + str.substr(0, 1);
    }
}

bool isPalindrome(string str) {
    if (str.size() <= 1) {
        return true;
    } else if (str[0] != str[str.size() - 1]) {
        return false;
    }
    return isPalindrome(str.substr(1, str.size() - 2));
}



int sumOfDigits(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sumOfDigits(n-1);
}

int printBackwards(int n) {
    if (n == 1) 
        return 1;
    
    cout << n << endl;
    printBackwards(n - 1);
}


int power(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    return base * exp(base, exp - 1);
}