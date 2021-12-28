#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1012

int arr[51][51];		//배추 심은 곳 좌표
int M, N;		//(가로 길이),(세로 길이)

bool promising(int x, int y) {
	bool TF = false;

	//본인 노드
	if (arr[y][x] == 1) {
		TF = true;
	}

	//노드 기준 상하좌우 살피기
	if (x > 0 && arr[y][x - 1] == 1) {		//왼쪽
		TF = true;
	}
	if (x < M - 1 && arr[y][x + 1] == 1) {		//오른쪽
		TF = true;
	}
	if (y > 0 && arr[y - 1][x] == 1) {		//위쪽
		TF = true;
	}
	if (y < N - 1 && arr[y + 1][x] == 1) {		//아래쪽
		TF = true;
	}
	
	return TF;
}

void backtrack(int x, int y) {
	if (promising(x, y)) {		//promising한지 확인
		//체크 했으므로 2로 바꾸기
		if (arr[y][x] == 1) {
			arr[y][x] = 2;
		}
		//상하좌우 백트래킹
		if (x > 0 && arr[y][x - 1] == 1) {		//왼쪽
			backtrack(x - 1, y);
		}
		if (x < M - 1 && arr[y][x + 1] == 1) {		//오른쪽
			backtrack(x + 1, y);
		}
		if (y > 0 && arr[y - 1][x] == 1) {		//위쪽
			backtrack(x, y - 1);
		}
		if (y < N - 1 && arr[y + 1][x] == 1) {		//아래쪽
			backtrack(x, y + 1);
		}
	}
}

int main(void) {
	int T;		//Test case
	int K, X, Y;		//X, Y 좌표 입력
	int count;		//지렁이 수

	cin >> T;
	for (int t = 0; t < T; t++) {
		count = 0;		//Test 마다 지렁이 수 초기화

		//M, N, K 입력
		cin >> M >> N >> K;

		//배열 초기화
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				arr[n][m] = 0;
			}
		}

		//X,Y 입력
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			arr[Y][X] = 1;
		}

		//backtracking
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (arr[n][m] == 1) {		//백트레킹 할 때마다 지렁이수++
					count++;
					backtrack(m,n);
				}
			}
		}

		//출력
		cout << count << "\n";
	}

	return 0;
}