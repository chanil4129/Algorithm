#include <bits/stdc++.h>
#define EPSILON 0.000001
using namespace std;

int n;
vector<pair<int, int>> v;
int d[55];
int ans;

int main() {
    int input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back({i, input});
        d[i] = n - 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            double incline =
                (double)(v[i].second - v[j].second) / (v[i].first - v[j].first);
            if (i > j) {
                for (int k = j + 1; k < i; k++) {
                    if (incline * (k - j) + (v[j].second - v[k].second) <
                        EPSILON) {
                        d[i]--;
                        break;
                    }
                }
            } else {
                for (int k = i + 1; k < j; k++) {
                    if (incline * (k - i) + (v[i].second - v[k].second) <
                        EPSILON) {
                        d[i]--;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    cout << ans;
}