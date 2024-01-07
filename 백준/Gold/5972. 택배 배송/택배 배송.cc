#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> v[51234];
// ex. v[4][3]값이 {2,3}이면, 4번 길은 2번길과 소 3마리로 이어져 있다는 뜻.
int d[51234];

void fun(int vertex) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;  // {거리, 정점}
    pq.push({0, vertex});
    d[vertex] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            if (d[ver] + v[ver][i].second < d[v[ver][i].first]) {
                d[v[ver][i].first] = d[ver] + v[ver][i].second;
                pq.push({v[ver][i].second, v[ver][i].first});
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    int a_input, b_input, c_input;
    for (int i = 0; i < m; i++) {
        cin >> a_input >> b_input >> c_input;
        v[a_input].push_back({b_input, c_input});
        v[b_input].push_back({a_input, c_input});
    }
    for (int i = 1; i <= n; i++) {
        d[i] = 1234567890;
    }
    fun(1);
    cout << d[n];
}