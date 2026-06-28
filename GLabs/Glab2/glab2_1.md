#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int &i : w) cin >> i;

    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int weight : w) {
            if (i >= weight) dp[i] = min(dp[i], dp[i - weight] + 1);
        }
    }

    cout << (dp[x] > 1e6 ? -1 : dp[x]) << "\n";
    return 0;
}