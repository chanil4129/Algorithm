#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(void) {
    while (true) {
        cin >> s;
        if (s == "end") {
            return 0;
        }

        bool isV = false;  // 1번 조건
        bool isT = true;   // 2번 조건
        bool isS = true;   // 3번 조건
        stack<char> cs;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                isV = true;
            }

            if (!cs.empty() && isT) {
                if (isVowel(cs.top())) {
                    if (isVowel(s[i])) {
                        if (cs.size() == 2) {
                            isT = false;
                        }
                    } else {
                        while (!cs.empty()) {
                            cs.pop();
                        }
                    }
                } else {
                    if (isVowel(s[i])) {
                        while (!cs.empty()) {
                            cs.pop();
                        }
                    } else {
                        if (cs.size() == 2) {
                            isT = false;
                        }
                    }
                }
            }
            if (isT) {
                cs.push(s[i]);
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