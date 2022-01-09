#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int n, m;
vector<pair<int, int>> node[1003];
vector<int> ans_num;
int d[1003], visit[1003];

int main(void) {
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		node[a].push_back(make_pair(c, b));
	}
	cin >> a >> b;
	for (int i = 1; i <= n; i++) d[i] = INF;
	d[a] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, a);
	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (current == b) break;
		if (d[current] < cost) continue;
		for (int i = 0; i < node[current].size(); i++) {
			int next = node[current][i].second;
			int next_cost = cost + node[current][i].first;		//이전 경로도 포함하는거 주의
			if (d[next] > next_cost) {
				visit[next] = current;
				d[next] = next_cost;
				pq.emplace(-next_cost, next);
			}
		}
	}	
	int t = b;
	while (t) {
		ans_num.push_back(t);
		t = visit[t];
	}
	cout << d[b] << "\n";
	cout << ans_num.size() << "\n";
	for (int i = ans_num.size() - 1; i >= 0; i--) cout << ans_num[i] << " ";
	return 0;
}

//https://www.acmicpc.net/problem/11779