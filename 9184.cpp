#include <iostream>
using namespace std;

int abc[21][21][21];		//저장할 값

int w(int a, int b, int c) {		//조건에 따라 설정
	if (a <= 0 || b <= 0 || c <= 0) return 1;		
	else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	//값을 abc[a][b][c]에 넣어주면서 중복계산 줄이기
	else if (abc[a][b][c] != 0) return abc[a][b][c];
	else if (a < b && b < c) return abc[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return abc[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
	int A, B, C;
	while (true) {
		cin >> A >> B >> C;		//입력
		if (A == -1 && B == -1 && C == -1) break;		//-1 -1 -1 입력하면 종료
		printf("w(%d, %d, %d) = %d\n", A, B, C, w(A, B, C));		//출력
	}
	return 0;
}

//https://www.acmicpc.net/problem/9184