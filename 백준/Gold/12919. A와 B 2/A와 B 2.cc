#include <bits/stdc++.h>
using namespace std;

string s, t;
map<int, int> m;

// 역으로 추적
void fun(string a) {
    if (s == a) {
        m[1] = 1;
    }

    if (s.length() == a.length()) {
        return;
    }

    char f = a.front();
    char b = a.back();

    if (f == 'B' && b == 'A') {
        // B~
        string aclone1 = a;
        aclone1.pop_back();
        fun(aclone1);

        // A~
        string aclone2 = a;
        reverse(aclone2.begin(), aclone2.end());
        aclone2.pop_back();
        fun(aclone2);
    } else if (f == b) {
        // B~
        string aclone = a;
        if (f == 'B') {
            reverse(aclone.begin(), aclone.end());
        }
        aclone.pop_back();
        fun(aclone);
    } else {
        // 불가능
        return;
    }
}

int main() {
    cin >> s >> t;
    fun(t);
    if (m[1]) {
        cout << 1;
    } else {
        cout << 0;
    }
}