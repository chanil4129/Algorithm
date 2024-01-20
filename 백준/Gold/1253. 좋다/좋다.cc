#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int ans;
int d[2222];

int main(void) {
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            bool exist = false;
            if (i == j) {
                continue;
            }
            int idx = lower_bound(v.begin(), v.end(), v[i] - v[j]) - v.begin();
            while (idx < v.size() && v[idx] == v[i] - v[j]) {
                if (idx != i && idx != j) {
                    exist = true;
                    break;
                }
                idx++;
            }
            if (exist) {
                d[i] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i]) {
            ans++;
        }
    }
    cout << ans;
}
