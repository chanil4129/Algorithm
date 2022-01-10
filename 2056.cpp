#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, run_time[10001], state[10001], result[10001];		//(작업 개수),(정점 사이에 걸리는 시간),(진입 차수),(시작점 부터 시작하여 총 걸리는 시간=>여기서 가장 큰 결과값은 문제의 정답)
vector<int> v[10001];		//(인접 노드 나타내기)

void topologySort() {		//위상 정렬
	queue<int> q;		//큐
	for (int i = 1; i <= N; i++) if (state[i] == 0) {		//처음 시작점 큐에 넣기
		q.push(i);		//정점 추가
		result[i] = run_time[i];		//결과값 갱신
	}
	for (int i = 1; i <= N; i++) {
		//if (q.empty()) return;		//사이클 발생시 종료(지금 문제에는 지장 없음)
		int temp = q.front();		//pop하기 전 정보 가지고 있기
		q.pop();
		for (int j = 0; j < v[temp].size(); j++) {		//인접 노드들 확인하면서
			int zero = v[temp][j];		
			if (--state[zero] == 0) q.push(zero);		//진입차수도 낮추고(간선 제거), 정점 추가
			result[zero] = max(result[zero], result[temp] + run_time[zero]);		//결과값 갱신
		}
	}
}

int main(void) {
	int w_num, w, ans=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> run_time[i] >> w_num;
		for (int j = 0; j < w_num; j++) {
			cin >> w;
			v[w].push_back(i);
			state[i]++;		//진입 차수 높이기(간선 추가)
		}
	}
	topologySort();		//위상 정렬
	for (int i = 1; i <= N; i++) ans = max(ans, result[i]);		//결과값 중 가장 큰 값 찾기=>정답
	cout << ans;		//답 출력
}

//https://www.acmicpc.net/problem/2056