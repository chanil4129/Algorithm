#include <iostream>
using namespace std;

int d[101][101];		//인접행렬

int main(void) {
	int N, M;		//(물건 개수),(물건들 사이 관계)
	int a, b;		//(무거운 물건),(가벼운 물건)
	cin >> N >> M;		//입력
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b]=1;		//방향성 그래프로 관계가 있다면 1로 만들기
	}
	//floyd 알고리즘
	for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if (d[i][k] && d[k][j]) d[i][j] = 1;
	for (int i = 1; i <= N; i++) {
		int cnt = -1;		//자기자신을 카운트할 때 포함하기 때문에 -1로 초기화
		for (int j = 1; j <= N; j++) if (!d[i][j] && !d[j][i]) cnt++;		//예시로 1->3, 3->1 중 하나라도 관계가 있다면 카운트x
		cout << cnt << "\n";		//출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/10159