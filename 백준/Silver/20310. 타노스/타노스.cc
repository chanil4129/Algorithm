#include <bits/stdc++.h>
using namespace std;

string s;
deque<int> zero;
deque<int> one;

int main(void) {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            zero.push_back(i);
        } else {
            one.push_back(i);
        }
    }
    int zeroCnt = zero.size() / 2;
    int oneCnt = one.size() / 2;
    for (int i = 0; i < zeroCnt; i++) {
        zero.pop_back();
    }
    for (int i = 0; i < oneCnt; i++) {
        one.pop_front();
    }
    string ans = "";
    for (int i = 0; i < zeroCnt + oneCnt; i++) {
        while (!zero.empty() && !one.empty()) {
            if (zero.front() < one.front()) {
                ans += '0';
                zero.pop_front();
            } else {
                ans += '1';
                one.pop_front();
            }
        }
        while (!zero.empty()) {
            ans += '0';
            zero.pop_front();
        }
        while (!one.empty()) {
            ans += '1';
            one.pop_front();
        }
    }
    cout << ans;
}