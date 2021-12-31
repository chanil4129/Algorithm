#include <iostream>
using namespace std;

int N, M;
bool promising[10] = {};

void backtracking(int level, int index) {
	if (level == M) {		//상태공간 트리에서 M까지 레벨에 도달하면
		for (int i = 1; i <= N; i++) {		//promising 배열 값이 true인것들 출력
			if (promising[i] == true) cout << i << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = index + 1; i <= N; i++) {		//뽑은 수보다 무조건 큰것만 확인
			if (promising[i] == false) {		//promising 배열 값이 false이면 뽑기
				promising[i] = true;		//뽑았다는 의미
				backtracking(level + 1, i);		//백트래킹
				promising[i] = false;		//초기화(중요)
			}
		}
	}
}

int main(void) {
	cin >> N >> M;		//입력
	backtracking(0,0);		//백트래킹
	return 0;
}

//https://www.acmicpc.net/problem/15650