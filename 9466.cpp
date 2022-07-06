#include <iostream>
#include <string.h>		//memset을 쓰기 위함
using namespace std;

int n, D;		//(정점 개수),(출력할 답)
int node[100001], state[100001];		//(node 관계),(진입 차수)
bool result[100001];		//(각 index별 카운팅 했는지 결과)

void dfs(int i) {
	result[i] = true;		//카운팅
	D++;		//출력할 답++, 
	state[node[i]]--;		//진입차수--
	if (!result[node[i]] && !state[node[i]]) dfs(node[i]);		//자식노드들 정점 확인(정점을 확인(카운팅)하지 않았다면, 진입차수가 0일때 dfs)
}

int main(void) {
	int T;		//(Test case)
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;		
		D = 0;		//Test case 마다 ans 초기화
		memset(state, 0, sizeof(state));		//Test case 마다 state 초기화
		memset(result, 0, sizeof(result));		//Test case 마다 result 초기화
		for (int j = 1; j <= n; j++) {
			cin >> node[j];		//j->node[j]
			state[node[j]]++;		//진입차수++
		}
		for (int j = 1; j <= n; j++) if (!result[j] && !state[j]) dfs(j);		//모든 정점들을 확인하면서 정점을 확인(카운팅)하지 않았다면, 진입차수가 0일때 dfs
		cout << D << "\n";		//결과 출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/9466