#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[112345];

int main() {
    cin >> n >> k;

    // n > k
    for (int i = 0; i <= n; i++) {
        d[i] = n - i;
    }

    // n < k
    for (int i = n + 1; i <= 100000; i++) {
        if (i % 2 == 0) {
            d[i] = min(d[i - 1] + 1, d[i / 2]);
        } else {
            d[i] = min({d[(i - 1) / 2] + 1, d[(i + 1) / 2] + 1, d[i - 1] + 1});
        }
    }
    cout << d[k];
}