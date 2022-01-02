#include <iostream>
using namespace std;

int N, cnt = 0;		//(입력),(출력)
int matrix[20] = {};		//row는 index, column은 값이라 생각하면 됨

bool promising(int row) {
	for (int i = 1; i < row; i++) if (!(matrix[row] - matrix[i]) || !(abs(row - i) - abs(matrix[row] - matrix[i]))) return false;		//세로, 대각선 확인해서 겹치면 가망하지 않음
	return true;		//그 외에는 가망함
}

void backtrack(int row) {
	if (promising(row)) {		//가망할때만
		if (row == N) cnt++;		//모든 row를 거치면 출력
		else for (int column = 1; column <= N; column++) {		//자식 노드에 모든 column 값을 넣어가면서
			matrix[row + 1] = column;		//자식 노드에 column값 넣기
			backtrack(row + 1);		//백트래킹
		}
	}
}

int main(void) {
	cin >> N;		//입력
	backtrack(0);		//백트래킹
	cout << cnt;		//출력
	return 0;
}

//https://www.acmicpc.net/problem/9663