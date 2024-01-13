#include <bits/stdc++.h>
using namespace std;

int n;
char game_kind;
set<string> p;
int ans;

int main(void) {
    cin >> n >> game_kind;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        p.insert(temp);
    }
    if (game_kind == 'Y') {
        ans = p.size();
    } else if (game_kind == 'F') {
        ans = p.size() / 2;
    } else if (game_kind == 'O') {
        ans = p.size() / 3;
    }
    cout << ans;
}