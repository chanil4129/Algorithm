#include <bits/stdc++.h>
using namespace std;

int R, C;
char MAP[1111][1111];
vector<pair<int, int>> fireStart;
pair<int, int> start;
bool Jflag[1111][1111];
bool fireFlag[1111][1111];
bool fireMove[2222];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int main(void) {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'F') {
                fireStart.push_back({i, j});
                fireFlag[i][j] = true;
            } else if (MAP[i][j] == 'J') {
                start = {i, j};
                Jflag[i][j] = true;
            }
        }
    }
    queue<pair<pair<int, int>, int>> q;
    queue<pair<int, int>> fire;
    for (int i = 0; i < fireStart.size(); i++) {
        fire.push({fireStart[i].first, fireStart[i].second});
    }
    q.push({{start.first, start.second}, 1});
    while (!q.empty()) {
        int ci = q.front().first.first;
        int cj = q.front().first.second;
        int ccnt = q.front().second;
        if (ci == 0 || ci == R - 1 || cj == 0 || cj == C - 1) {
            cout << ccnt;
            return 0;
        }
        q.pop();
        // 불 이동
        if (!fireMove[ccnt]) {
            fireMove[ccnt] = true;
            int fireSize = fire.size();
            for (int a = 0; a < fireSize; a++) {
                int fci = fire.front().first;
                int fcj = fire.front().second;
                fire.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int fi = fci + di[dir];
                    int fj = fcj + dj[dir];
                    if (fi >= 0 && fi < R && fj >= 0 && fj < C &&
                        !fireFlag[fi][fj] && MAP[fi][fj] == '.') {
                        fireFlag[fi][fj] = true;
                        MAP[fi][fj] = 'F';
                        fire.push({fi, fj});
                    }
                }
            }
        }
        // 지훈 이동
        for (int dir = 0; dir < 4; dir++) {
            int i = ci + di[dir];
            int j = cj + dj[dir];
            if (i >= 0 && i < R && j >= 0 && j < C && !Jflag[i][j] &&
                MAP[i][j] == '.') {
                Jflag[i][j] = true;
                q.push({{i, j}, ccnt + 1});
            }
        }
    }
    cout << "IMPOSSIBLE";
}
