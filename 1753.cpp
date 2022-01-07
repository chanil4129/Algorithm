#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int V, E, start;		//(정점 개수),(간선 개수),(시작 정점)
vector<pair<int, int>> node[20001];		//정점, 간선, 비용 정보를 담을 벡터
int d[200001];		//출력할 최단 경로값

void dijkstra() {
	d[start] = 0;		//시작점은 0
	priority_queue<pair<int, int>> pq;		//우선순위 큐를 통해 힙 구조 사용
	pq.push(make_pair(0, start));		//시작점은 비용 (0, start)
	while (!pq.empty()) {		//pair가 비어 있지 않을 때에만 반복
		int current = pq.top().second;		//현재 정점
		int distance = -pq.top().first;		//현재 비용(우선순위 큐는 최대 힙 구조를 갖기 때문에 이를 이용해 음수화 하기)
		pq.pop();		//큐에서 꺼내기
		//if (d[current] < distance) continue;		//최단거리가 아닌 경우 pass (없어도 채점결과에 영향x)
		for (int i = 0; i < node[current].size(); i++) {		//백터에 담긴 pair들 개수 만큼만
			int next = node[current][i].second;		//다음 정점
			int next_distance = distance + node[current][i].first;		//다음 비용
			if (d[next] > next_distance) {		//다음 비용이 현재 적힌 최단 경로값보다 더 적다면
				d[next] = next_distance;		//새로 갱신
				pq.push(make_pair(-next_distance, next));		//정점 추가(우선순위 큐는 최대 힙 구조를 갖기 때문에 이를 이용해 음수화 하기)
			}
		}
	}
}

int main(void) {
	int u, v, w;		//(정점1),(정점2),(비용)
	cin >> V >> E >> start;		//입력
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;		//입력
		node[u].push_back(make_pair(w, v));		//출발할 정점 벡터, 그리고 first에는 비용, second에는 도착 정점(이유는 코드 아래 설명)
	}
	for (int i = 1; i <= V; i++) d[i] = INF;		//연결 간선이 없다면 INF로 초기화
	dijkstra();		//다익스트라
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << "\n";		//만약 INF라면 "INF"를 출력
		else cout << d[i] << "\n";		//INF가 아니라면 비용 그대로 출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/1753