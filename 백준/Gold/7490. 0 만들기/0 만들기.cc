#include <bits/stdc++.h>
using namespace std;

int t, n;

bool isZero(string s) {
    vector<int> digit;
    vector<char> op;
    string p = "";
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i])) {
            if (s[i] == ' ') {
                continue;
            }
            op.push_back(s[i]);
            digit.push_back(stoi(p));
            p = "";
        } else {
            p += s[i];
        }
    }
    digit.push_back(stoi(p));

    int result = digit[0];
    for (int i = 0; i < digit.size() - 1; i++) {
        if (op[i] == '+') {
            result += digit[i + 1];
        } else {
            result -= digit[i + 1];
        }
    }
    return !result;
}

void fun(string s, int dep) {
    if (dep >= n) {
        if (isZero(s)) {
            cout << s << "\n";
        }
        return;
    }

    fun(s + " " + to_string(dep + 1), dep + 1);
    fun(s + "+" + to_string(dep + 1), dep + 1);
    fun(s + "-" + to_string(dep + 1), dep + 1);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        fun("1", 1);
        cout << "\n";
    }
}