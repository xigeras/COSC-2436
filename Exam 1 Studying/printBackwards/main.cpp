#include <iostream>
using namespace std;

void printBackwards(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    printBackwards(n - 1);
}

int main()
{

    printBackwards(5);

    return 0;
}