#include <bits/stdc++.h>
using namespace std;

int n;
int bd[112345];
stack<pair<int, int>> ls;
stack<pair<int, int>> rs;
int num[112345];
map<int, pair<int, int>> near;

int main(void) {
    cin >> n;
    ls.push({112345, 0});
    rs.push({112345, 0});
    for (int i = 1; i <= n; i++) {
        cin >> bd[i];
    }
    for (int i = 1; i <= n; i++) {
        int height;
        int idx;
        while (true) {
            height = ls.top().first;
            idx = ls.top().second;
            if (bd[i] < height) {
                break;
            }
            ls.pop();
            num[idx] += ls.size() - 1;
            near[idx].first = ls.top().second;
        }
        ls.push({bd[i], i});
    }
    while (ls.size() != 1) {
        int height = ls.top().first;
        int idx = ls.top().second;
        ls.pop();
        num[idx] += ls.size() - 1;
        near[idx].first = ls.top().second;
    }
    for (int i = n; i >= 1; i--) {
        int height;
        int idx;
        while (true) {
            height = rs.top().first;
            idx = rs.top().second;
            if (bd[i] < height) {
                break;
            }
            rs.pop();
            num[idx] += rs.size() - 1;
            near[idx].second = rs.top().second;
        }
        rs.push({bd[i], i});
    }
    while (rs.size() != 1) {
        int height = rs.top().first;
        int idx = rs.top().second;
        rs.pop();
        num[idx] += rs.size() - 1;
        near[idx].second = rs.top().second;
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            cout << "0\n";
        } else {
            if (near[i].first == 0 || near[i].second == 0) {
                cout << num[i] << " " << max(near[i].first, near[i].second)
                     << "\n";
            } else if (i - near[i].first > near[i].second - i) {
                cout << num[i] << " " << near[i].second << "\n";
            } else {
                cout << num[i] << " " << near[i].first << "\n";
            }
        }
    }
}