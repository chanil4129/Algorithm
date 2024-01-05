#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int n, l, r;
int a[55][55];
int isTeam[55][55];
vector<vector<pi>> team;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans;

void findGroup(int ax, int ay) {
    if (isTeam[ax][ay]) {
        return;
    }
    vector<pi> group;
    queue<pi> q;

    group.push_back({ax, ay});
    q.push({ax, ay});
    isTeam[ax][ay] = 1;
    while (!q.empty()) {
        pi cur = q.front();
        int curPopul = a[cur.first][cur.second];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < n && !isTeam[x][y] &&
                abs(curPopul - a[x][y]) >= l && abs(curPopul - a[x][y]) <= r) {
                isTeam[x][y] = 1;
                group.push_back({x, y});
                q.push({x, y});
            }
        }
    }
    if (group.size() >= 2) {
        team.push_back(group);
    }
}

void immigration() {
    int resultPopul;
    int sumAllPopul = 0;
    for (int i = 0; i < team.size(); i++) {
        sumAllPopul = 0;
        for (int j = 0; j < team[i].size(); j++) {
            sumAllPopul += a[team[i][j].first][team[i][j].second];
        }
        resultPopul = sumAllPopul / team[i].size();
        for (int j = 0; j < team[i].size(); j++) {
            a[team[i][j].first][team[i][j].second] = resultPopul;
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        memset(isTeam, 0, sizeof(isTeam));
        team.clear();
        // 연합 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                findGroup(i, j);
            }
        }
        // 팀이 있는지 확인
        if (team.empty()) {
            cout << ans;
            return 0;
        }
        // 이주
        immigration();
        ans++;
    }
}