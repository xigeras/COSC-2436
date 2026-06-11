#include <iostream>
#include <time>

using namespace std;


int main() {
    clock_t beg, end;
    beg = clock();

    bubbleSort(...);

    end = clock();


    cout << "time taken" << float(end-beg/CLOCKS_PER_SEC)*1000.546;

    beg = clock();
    bubbleSort(a1, 100);
    end = clock();

    cout << "time taken" << (end-beg/CLOCKS_PER_SEC);

    return 0;
}