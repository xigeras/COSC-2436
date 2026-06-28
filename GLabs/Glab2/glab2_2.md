#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    int a, b;
    cin >> n;
    map<int, int> events;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        events[a]++;
        events[b]--;
    }

    int current = 0, peak = 0;
    for (auto const& [time, change] : events) {
        current += change;
        peak = max(peak, current);
    }
    cout << peak << "\n";
    return 0;
}