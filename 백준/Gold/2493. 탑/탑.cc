#include <bits/stdc++.h>
using namespace std;

int n;
stack<pair<int, int>> s;
map<int, int> ans;

int main() {
    cin >> n;
    int height;
    s.push({112345678, 0});
    for (int i = 0; i < n; i++) {
        cin >> height;
        while (!s.empty() && s.top().first <= height) {
            int towerIdx = s.top().second;
            s.pop();
            int nextTowerIdx = s.top().second;
            ans[towerIdx] = nextTowerIdx;
        }
        s.push({height, i + 1});
    }
    while (s.size() > 1) {
        int towerIdx = s.top().second;
        s.pop();
        int nextTowerIdx = s.top().second;
        ans[towerIdx] = nextTowerIdx;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}