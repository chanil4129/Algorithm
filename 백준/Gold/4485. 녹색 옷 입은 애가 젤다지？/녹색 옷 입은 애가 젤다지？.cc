#include <bits/stdc++.h>
#define INF 123456789
using namespace std;

int n;
int problem;
int MAP[130][130];
int d[130][130];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void fun() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = INF;
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    pq.push({MAP[0][0], {0, 0}});
    d[0][0] = MAP[0][0];
    while (!pq.empty()) {
        int curVal = pq.top().first;
        int curCorX = pq.top().second.first;
        int curCorY = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nextCorX = curCorX + dx[i];
            int nextCorY = curCorY + dy[i];
            if (nextCorX >= 0 && nextCorX < n && nextCorY >= 0 &&
                nextCorY < n &&
                d[curCorX][curCorY] + MAP[nextCorX][nextCorY] <
                    d[nextCorX][nextCorY]) {
                d[nextCorX][nextCorY] =
                    d[curCorX][curCorY] + MAP[nextCorX][nextCorY];
                pq.push({MAP[nextCorX][nextCorY], {nextCorX, nextCorY}});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (++problem) {
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> MAP[i][j];
            }
        }
        fun();
        cout << "Problem " << problem << ": " << d[n - 1][n - 1] << "\n";
    }
}
