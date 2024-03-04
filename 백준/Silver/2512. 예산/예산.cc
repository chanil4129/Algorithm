#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> v;
int s;

int main(void) {
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        s += input;
        v.push_back(input);
    }
    cin >> m;
    sort(v.rbegin(), v.rend());
    int ans = v[0];
    int flat;
    while (true) {
        for (int i = 0; i < v.size(); i++) {
            if (ans < v[i]) {
                v[i] = ans;
            }
        }
        flat = 0;
        for (int i = 0; i < v.size(); i++) {
            flat += v[i];
        }
        if (flat <= m) {
            break;
        }
        ans--;
    }
    cout << ans;
}