#include <bits/stdc++.h>
using namespace std;

int R, C;
char MAP[23][23];
bool flag[23][23];
map<char, bool> al;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans;

void fun(int r, int c, int cnt) {
    bool canGo = false;
    for (int i = 0; i < 4; i++) {
        int x = c + dx[i];
        int y = r + dy[i];
        if (x > 0 && x <= C && y > 0 && y <= R && !flag[y][x] &&
            !al[MAP[y][x]]) {
            canGo = true;
            flag[y][x] = true;
            al[MAP[y][x]] = true;
            fun(y, x, cnt + 1);
            flag[y][x] = false;
            al[MAP[y][x]] = false;
        }
    }
    if (!canGo) {
        ans = max(ans, cnt);
        return;
    }
}

int main(void) {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < 26; i++) {
        al['A' + i] = false;
    }
    flag[1][1] = true;
    al[MAP[1][1]] = true;
    fun(1, 1, 1);
    cout << ans;
}
