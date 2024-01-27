#include <bits/stdc++.h>
using namespace std;

int n, newScore, p;
vector<int> v;

int main(void) {
    cin >> n >> newScore >> p;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    if (n == p && newScore <= v[v.size() - 1]) {
        cout << -1;
        return 0;
    }
    v.push_back(newScore);
    sort(v.begin(), v.end());
    int idx =
        v.size() - (upper_bound(v.begin(), v.end(), newScore) - v.begin()) + 1;
    if (idx > p) {
        cout << -1;
        return 0;
    }
    cout << idx;
}
