#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n, a, b, current = 0, maxCust = 0;
    cin >> n;
    map<int, int> events;
    while (n--) {
        cin >> a >> b;
        events[a]++;
        events[b]--;
    }
    for (auto const& [time, count] : events) {
        current += count;
        maxCust = max(maxCust, current);
    }
    cout << maxCust << "\n";
    return 0;
}