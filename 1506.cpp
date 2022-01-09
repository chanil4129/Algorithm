#include <iostream>
using namespace std;

int N;		//도시 개수
int visit[101][101];		//도시 관계(인접행렬)
int cost[101], visited[101];		//(도시 건설 비용),(독립적인 묶음인지 확인->비용을 체크하기 위함인데, 각 묶음에서 가장 적은 비용을 더해준다) 

int main(void) {
	int ans = 0;		//출력할 답(최소비용)
	string input;		//인접행렬 입력
	cin >> N;
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) visit[i][j] = input[j] - '0';		//붙여서 입력하므로 값을 따로 받아줘야함
	}
	//플로이드 알고리즘을 통해 경로 파악
	for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (visit[i][k] && visit[k][j]) visit[i][j] = 1;
	for (int i = 0; i < N; i++) if (!visited[i]) {		//방문하지 않은 집단일때만 실행(방문 안했으면 0)
		int k = cost[i];		//최소 비용
		for (int j = 0; j < N; j++) if (visit[i][j] & visit[j][i]) {		//왔다갔다 할 수 있는 도시들만 하나의 집단이므로 그때만 실행
			if (k > cost[j]) k = cost[j];		//그 집단에서 최소비용으로 갱신
			visited[j] = 1;		//방문한 집단이므로 1로 바꿔주기
		}
		ans += k;		//한 집단에서 최소비용을 더해주기
	}
	cout << ans;		//답 출력
	return 0;
}

//https://www.acmicpc.net/problem/1506