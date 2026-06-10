#include <iostream>

using namespace std;


int main() {
    int n; 
    int count = 0;
    cin >> n;
 
    while (n > 0) {
        int max = 0;
        int temp = n;

        while (temp > 0) {
            int d = temp % 10;
            if (d > max) {
                max = d;
            }
            temp = temp / 10;
        }
        n = n - max;
        count++;
    }


    cout << count << endl;
}


// NEED A MAX. while loop would be better