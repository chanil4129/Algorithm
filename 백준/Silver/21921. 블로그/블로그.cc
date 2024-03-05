#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;
pair<int, int> ans;  //{방문자수, 몇개의 기간}

int main(void) {
    cin >> n >> x;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    // 초기화
    ans.first = 0;
    for (int i = 0; i < x; i++) {
        ans.first += v[i];
    }
    ans.second = 1;
    // 찾기
    int cur = ans.first;
    for (int i = 1; i <= v.size() - x; i++) {
        cur = cur - v[i - 1] + v[i + x - 1];
        if (ans.first < cur) {
            ans.first = cur;
            ans.second = 1;
        } else if (ans.first == cur) {
            ans.second++;
        }
    }
    if (ans.first == 0) {
        cout << "SAD";
        return 0;
    }
    cout << ans.first << "\n" << ans.second;
}