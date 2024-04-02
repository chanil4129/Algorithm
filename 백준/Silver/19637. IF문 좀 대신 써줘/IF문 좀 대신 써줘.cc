#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<string, int>> cStyle;

string findStyle(int war) {
    int left = 0;
    int right = cStyle.size() - 1;
    int mid = (left + right) / 2;
    while (left <= right) {
        mid = (left + right) / 2;
        if (war <= cStyle[mid].second) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (war > cStyle[mid].second) {
        return cStyle[mid + 1].first;
    }
    return cStyle[mid].first;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    string a;
    int b;
    cin >> a >> b;
    cStyle.push_back({a, b});
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        if (b != cStyle[i - 1].second) {
            cStyle.push_back({a, b});
        }
    }
    int war;
    string ans;
    for (int i = 0; i < M; i++) {
        cin >> war;
        ans = findStyle(war);
        cout << ans << "\n";
    }
}