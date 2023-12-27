#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> d;
int dp[111][123456];

int main(void) {
    cin >> n >> k;
    int w, v;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        d.push_back({w, v});
    }
    for (int i = 1; i <= n; i++) {
        w = d[i - 1].first;
        v = d[i - 1].second;
        for (int j = 1; j <= k; j++) {
            if (j - w >= 0) {
                dp[i][j] = max(dp[i - 1][j - w] + v, dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][k];
}