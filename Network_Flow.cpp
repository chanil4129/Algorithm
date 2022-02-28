#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100
#define INF 1000000000

int n = 6, result;
int capacity[MAX][MAX], flow[MAX][MAX], d[MAX];
vector<int> v[MAX];

void network_flow(int start, int end) {//dfs라고 생각하면 됨
	while (1) {
		fill(d, d + MAX, -1);		//d 모든 값 -1로 초기화(경로 다시출발)
		queue<int> q;		//큐로 dfs
		q.push(start);		
		while (!q.empty()) {
			int x = q.front();		//꺼내면서
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {		//인접 길들
				int y = v[x][i];
				if (capacity[x][y] - flow[x][y] > 0 && d[y] == -1) {		//방문 안한것들중 용량 남은 경우 경로추가
					q.push(y);
					d[y] = x;
					if (y == end) break;		//다 도착한경우
				}
			}
		}
		if (d[end] == -1) break;		//경로가 더이상 없으면 종료
		int f = INF;		//초기화(min을 찾기 위해)
		for (int i = end; i != start; i = d[i]) f = min(f, capacity[d[i]][i] - flow[d[i]][i]);		//유량 판단
		for (int i = end; i != start; i = d[i]) {		//유량 넣기
			flow[d[i]][i] += f;
			flow[i][d[i]] -= f;
		}
		result += f;		//총 사용 유량
	}
}

int main(void) {
	v[1].push_back(2);
	v[2].push_back(1);
	capacity[1][2] = 12;

	v[1].push_back(4);
	v[4].push_back(1);
	capacity[1][4] = 11;

	v[2].push_back(3);
	v[3].push_back(2);
	capacity[2][3] = 6;

	v[2].push_back(4);
	v[4].push_back(2);
	capacity[2][4] = 3;

	v[2].push_back(5);
	v[5].push_back(2);
	capacity[2][5] = 5;

	v[2].push_back(6);
	v[6].push_back(2);
	capacity[2][6] = 9;

	v[3].push_back(6);
	v[6].push_back(3);
	capacity[3][6] = 8;

	v[4].push_back(5);
	v[5].push_back(4);
	capacity[4][5] = 9;

	v[5].push_back(3);
	v[3].push_back(5);
	capacity[5][3] = 3;

	v[5].push_back(6);
	v[6].push_back(5);
	capacity[5][6] = 4;

	network_flow(1, 6);
	printf("%d", result);
	return 0;
}

