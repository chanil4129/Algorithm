#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    while (true) {
        cin >> s;
        if (s == "end") {
            return 0;
        }

        bool isV = false;
        bool isT = true;
        bool isS = true;
        stack<char> c;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                isV = true;
            }

            if (!c.empty() && isT) {
                if (c.top() == 'a' || c.top() == 'e' || c.top() == 'i' ||
                    c.top() == 'o' || c.top() == 'u') {
                    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                        s[i] == 'o' || s[i] == 'u') {
                        if (c.size() == 2) {
                            isT = false;
                        } else {
                            c.push(s[i]);
                        }
                    } else {
                        while (!c.empty()) {
                            c.pop();
                        }
                        c.push(s[i]);
                    }
                } else {
                    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                        s[i] == 'o' || s[i] == 'u') {
                        while (!c.empty()) {
                            c.pop();
                        }
                        c.push(s[i]);
                    } else {
                        if (c.size() == 2) {
                            isT = false;
                        } else {
                            c.push(s[i]);
                        }
                    }
                }
            } else if (isT) {
                c.push(s[i]);
            }

            if (i > 0 && !(s[i] == 'e' || s[i] == 'o') && s[i - 1] == s[i]) {
                isS = false;
            }
        }

        if (isV && isT && isS) {
            cout << "<" << s << "> is acceptable.\n";
        } else {
            cout << "<" << s << "> is not acceptable.\n";
        }
    }
}