#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> dic;

bool fun(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main(void) {
    cin >> n >> m;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input.length() < m) {
            continue;
        }
        if (dic.find(input) != dic.end()) {
            dic[input]++;
        } else {
            dic[input] = 1;
        }
    }
    vector<pair<string, int>> v(dic.begin(), dic.end());
    sort(v.begin(), v.end(), fun);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << "\n";
    }
}