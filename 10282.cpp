#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;		//INF 값 설정(연결 안됐을 경우)
int T, n, d, c, cnt;		//(Test case),(컴퓨터 개수),(의존성 개수),(해킹당한 컴퓨터 번호.즉 시작 번호)
vector<pair<int, int>> computer[10001];		//인접한 정점을 나타내기 위한 백터. first에 시간(비용), seconde에 의존 당하는 정점
int total_time[10001];		//총 소요 시간

void infection() {		//다익스트라 알고리즘으로 해결
	total_time[c] = 0;		//시작 컴퓨터
	priority_queue<pair<int, int>> pq;		//우선순위 큐를 사용해 힙으로 해결하기 위함
	pq.emplace(0, c);		//시작 정보
	while (!pq.empty()) {		//큐가 비어있지 않다면
		int current = pq.top().second;		//현재 컴퓨터
		int cost = -pq.top().first;		//현재 시간(max 힙이므로 음수화를 이용)
		pq.pop();		//pop
		if (total_time[current] < cost) continue;		//최단시간이 아닌 경우 pass 
		for (int i = 0; i < computer[current].size(); i++) {		////백터에 담긴 pair들 개수 만큼만
			int next = computer[current][i].second;		//다음 컴퓨터
			int next_cost = cost + computer[current][i].first;		//다음 컴퓨터의 시간
			if (total_time[next] > next_cost) {		//다음 시간이 현재 적힌 최단 시간보다 더 적다면
				total_time[next] = next_cost;		//새로 갱신
				pq.emplace(-next_cost, next);		//컴퓨터 추가(우선순위 큐는 최대 힙 구조를 갖기 때문에 이를 이용해 음수화 하기)
			}
		}
	}
}

int main(void) {
	int a, b, s, max;		//(의존a),(의존b),(시간),(최댓값)
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> d >> c;
		for (int j = 1; j <= n; j++) while (!computer[j].empty()) computer[j].pop_back();		//매번 case마다 백터 초기화
		for (int j = 0; j < d; j++) {
			cin >> a >> b >> s;
			computer[b].push_back(make_pair(s, a));		//인접행렬 정보 입력(순서 주의)
		}
		for (int j = 1; j <= n; j++) total_time[j] = INF;		//의존하지 않고 있다면 INF
		cnt = 0; max = 0;		//매번 case마다 초기화
		infection();		//다익스트라
		for (int j = 1; j <= n; j++) if (total_time[j] != INF) {		//감염된 컴퓨터 수와 가장 마지막까지 감염된 시간 구하기
			if (max < total_time[j]) max = total_time[j];
			cnt++;
		}
		cout << cnt << " " << max << "\n";		//출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/10282