#include <bits/stdc++.h>
using namespace std;

int N, M;
int MAP[1111][1111];
int visitMAP[1111][1111][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &MAP[i][j]);
        }
    }

    queue<pair<pair<int, int>, int>> q;  // {{row, column},벽부쉈는지 여부}
    q.push({{1, 1}, 0});
    visitMAP[1][1][0] = 1;

    while (!q.empty()) {
        int curRow = q.front().first.first;
        int curCol = q.front().first.second;
        int curWall = q.front().second;
        q.pop();

        if (curRow == N && curCol == M) {
            cout << visitMAP[N][M][curWall];
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dx[i];
            int nextCol = curCol + dy[i];
            if (nextRow > 0 && nextRow <= N && nextCol > 0 && nextCol <= M) {
                if (MAP[nextRow][nextCol] && !curWall) {
                    visitMAP[nextRow][nextCol][1] =
                        visitMAP[curRow][curCol][curWall] + 1;
                    q.push({{nextRow, nextCol}, 1});
                } else if (!MAP[nextRow][nextCol] &&
                           !visitMAP[nextRow][nextCol][curWall]) {
                    visitMAP[nextRow][nextCol][curWall] =
                        visitMAP[curRow][curCol][curWall] + 1;
                    q.push({{nextRow, nextCol}, curWall});
                }
            }
        }
    }

    cout << -1;
}