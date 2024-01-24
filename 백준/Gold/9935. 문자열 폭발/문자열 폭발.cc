#include <bits/stdc++.h>
using namespace std;

string a;
string b;
stack<char> s1;
stack<char> s2;

int main(void) {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        s1.push(a[i]);
        bool isRemove = true;
        int blen = b.length();
        while (!s1.empty() && blen--) {
            if (s1.top() != b[blen]) {
                isRemove = false;
                while (!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
                break;
            }
            s2.push(s1.top());
            s1.pop();
        }
        if (s2.size() != b.length()) {
            isRemove = false;
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        if (isRemove) {
            while (!s2.empty()) {
                s2.pop();
            }
        }
    }
    while (!s2.empty()) {
        s2.pop();
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    if (s2.empty()) {
        cout << "FRULA";
        return 0;
    }
    while (!s2.empty()) {
        cout << s2.top();
        s2.pop();
    }
}
