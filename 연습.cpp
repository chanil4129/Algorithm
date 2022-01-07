#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int V, E, start;
vector<pair<int, int>> node[20001];
int d[20001];

void dijkstra() {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start);
	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < node[current].size(); i++) {
			int next = node[current][i].second;
			int next_cost = cost + node[current][i].first;
			if (d[next] > next_cost) {
				d[next] = next_cost;
				pq.emplace(-next_cost, next);
			}
		}
	}
}

int main(void) {
	int u, v, w;
	cin >> V >> E >> start;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		node[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= V; i++) d[i] = INF;
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << "\n";
		else cout << d[i] << "\n";
	}

	return 0;
}