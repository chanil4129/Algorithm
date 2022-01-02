#include <iostream>
using namespace std;

int N, M;		//입력할 변수
int check[10];		//출력할 배열

void backtrack(int level) {
	if (level == M) {		//깊이가 M이면 배열값들 출력
		for (int i = 0; i < M; i++) cout << check[i] << " ";
		cout << "\n";
	}
	//깊이가 M까지 도달할 때까지
	else for (int i = 1; i <= N; i++) {		//자식노드는 1부터 N까지
			check[level] = i;		//뽑기(배열값에 선택된 자식노드)
			backtrack(level + 1);		//백트래킹
	}
}

int main(void) {
	cin >> N >> M;		//입력
	backtrack(0);		//백트래킹
	return 0;
}

//https://www.acmicpc.net/problem/15651