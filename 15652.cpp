#include <iostream>
using namespace std;

int N, M;		//입력할 변수
int arr[10];		//출력할 배열

void backtrack(int level, int index) {
	if (level == M) {		//깊이가 M이면 배열값들 출력
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
	}
	//깊이가 M까지 도달할 때까지
	else for (int i = index; i <= N; i++) {		//자식노드는 부모노드 값부터 N까지
		arr[level] = i;		//뽑기(배열값에 선택된 자식노드)
		backtrack(level + 1, i);		//백트래킹
	}
}

int main(void) {
	cin >> N >> M;		//입력
	backtrack(0, 1);		//백트래킹
	return 0;
}

//https://www.acmicpc.net/problem/15652