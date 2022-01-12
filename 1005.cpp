#include <iostream>
#include <queue>
#include <vector>
#include <string.h>		//memset을 쓰기 위함
using namespace std;

int N, K, D[1001], state[1001], result[1001];		//(건물 개수),(규칙 개수),(건물 건설에 걸리는 시간),(건물 진입 차수),(결과 값)
vector<int> v[1001];		//인접 노드 정보

void topologySort() {		//위상정렬
	queue<int> q;		//큐
	for (int i = 1; i <= N; i++) if (state[i] == 0) {		//노드들 진입 차수 0이면
		q.push(i);		//큐에 넣기
		result[i] = D[i];		//결과 값 갱신
	}
	for (int i = 1; i <= N; i++) {		//모든 노드들 확인
		if (q.empty()) return;		//만약 비었으면 사이클이 생기므로 종료
		int temp = q.front();		//pop하기전 정보 저장
		q.pop();
		for (int j = 0; j < v[temp].size(); j++) {		//인접 노드들 확인하면서
			int zero = v[temp][j];
			if (--state[zero] == 0) q.push(zero);		//진입 차수 낮추면서 만약 노드의 진입 차수가 0이면 큐에 넣기
			result[zero] = max(result[zero], result[temp] + D[zero]);		//결과값 갱신
		}
	}
}

int main(void) {
	int T;		//(Test case)
	int X, Y;		//X->Y 노드 정보
	int W;		//W번 건물 짓는데 걸리는 시간
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 0; j <= N; j++) v[j].resize(0);		//벡터 초기화
		memset(D, 0, sizeof(D));		//D 초기화
		memset(state, 0, sizeof(state));		//state 초기화
		memset(result, 0, sizeof(result));		//result 초기화
		for (int j = 1; j <= N; j++) cin >> D[j];
		for (int k = 0; k < K; k++) {
			cin >> X >> Y;
			v[X].push_back(Y);
			state[Y]++;		//진입 차수 +1
		}
		cin >> W;
		topologySort();		//위상정렬
		cout << result[W] << "\n";		//W 건물 짓는 데 걸리는 시간 출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/1005