#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumOfDigits(n - 1);
}

int main()
{
    int x = 0;
    x = sumOfDigits(5);
    cout << "Sum of digits of 5 is " << x << endl;

    return 0;
}