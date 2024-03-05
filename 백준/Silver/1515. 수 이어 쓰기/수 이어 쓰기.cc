#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string input;
    cin >> input;
    int cur = 0;
    for (int i = 1;; i++) {
        string s = to_string(i);
        for (int j = 0; j < s.length(); j++) {
            if (input[cur] == s[j]) {
                cur++;
            }
        }
        if (cur == input.length()) {
            cout << i;
            return 0;
        }
    }
}