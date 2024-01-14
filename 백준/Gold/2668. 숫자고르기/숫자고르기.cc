#include <bits/stdc++.h>
using namespace std;

int n;
int d[111];
set<int> ans;
vector<int> v;

bool isEnd(int cur) {
    for (auto i : v) {
        if (i == cur) {
            return true;
        }
    }
    return false;
}

void fun(int start, int cur) {
    if (ans.find(start) != ans.end() || isEnd(cur)) {
        return;
    }
    if (start == d[cur]) {
        for (auto i : v) {
            ans.insert(i);
        }
        ans.insert(d[cur]);
        return;
    }
    v.push_back(cur);
    fun(start, d[cur]);
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        fun(i, i);
        v.clear();
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }
}
