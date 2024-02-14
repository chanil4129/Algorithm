#include <bits/stdc++.h>
using namespace std;
#define INF 1123456789

int n, m, x;
vector<pair<int, int>> v[1111];  // v[시작점]={비용,끝점}
int d[1111];
int ans;

int fun(int start, int end) {
    fill(d, d + n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});
    d[start] = 0;

    while (!pq.empty()) {
        int curVertex = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[curVertex].size(); i++) {
            int nextCost = v[curVertex][i].first;
            int nextVertex = v[curVertex][i].second;
            if (d[nextVertex] > d[curVertex] + nextCost) {
                d[nextVertex] = d[curVertex] + nextCost;
                pq.push({nextCost, nextVertex});
            }
        }
    }
    return d[end];
}

int main(void) {
    cin >> n >> m >> x;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }
    for (int i = 1; i <= n; i++) {
        if (i == x) {
            ans = max(ans, 0);
            continue;
        }
        ans = max(ans, fun(i, x) + fun(x, i));
    }
    cout << ans;
}