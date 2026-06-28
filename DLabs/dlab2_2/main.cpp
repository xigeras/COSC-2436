#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x, c;
    cin >> n >> x;
    vector<int> dp(x + 1, 1e9);

    dp[0] = 0;
    while (n--) {
        cin >> c;
        for (int i = c; i <= x; i++) {
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << "\n";
    return 0;
}
