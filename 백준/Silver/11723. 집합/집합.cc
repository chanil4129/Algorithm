#include <bits/stdc++.h>
using namespace std;

int m;
int a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;
    string cmd;
    int x;
    while (m--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            a |= 1 << x;
        } else if (cmd == "remove") {
            cin >> x;
            a &= ~(1 << x);
        } else if (cmd == "check") {
            cin >> x;
            if (a & 1 << x) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (cmd == "toggle") {
            cin >> x;
            if (a & 1 << x) {
                a &= ~(1 << x);
            } else {
                a |= 1 << x;
            }
        } else if (cmd == "all") {
            a = (1 << 21) - 1;
        } else if (cmd == "empty") {
            a = 0;
        }
    }
}