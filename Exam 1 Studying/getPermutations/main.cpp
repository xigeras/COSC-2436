#include <iostream>
using namespace std;

void getPermutations(string str, int start, int end)
{
    if (start == end)
    {
        cout << str << endl;
        return;
    }

    for (int i = start; i <= end; ++i)
    {
        swap(str[start], str[i]);
        getPermutations(str, start + 1, end);
        swap(str[start], str[i]);
    }
}

int main()
{
    string str = "abc";
    getPermutations(str, 0, str.length() - 1);

    return 0;
}