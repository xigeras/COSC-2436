#include <iostream>
using namespace std;

void printForwards(int n)
{
    if (n < 1)
    {
        return;
    }
    printForwards(n - 1);
    cout << n << " ";
}

int main()
{

    printForwards(5);

    return 0;
}