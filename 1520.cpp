#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T[501][501]; //table 지도 행렬
int D[501][501]; //D[1][1]이 답. 경로의 경우의 수를 담고 있음
int M, N; //세로, 가로

int dp(int m,int n) {
	//종료
	if (m == M && n == N) return 1;
	if (m < 1 || n < 1 || m > M || n > N) return 0;
	//중복
	int &ret = D[m][n];
	if (ret != -1) return ret;
	//탐색
	int sum = 0;
	if (n > 1 && T[m][n - 1] < T[m][n]) //위
		sum += dp(m, n - 1);
	if (n < N && T[m][n + 1] < T[m][n]) //아래
		sum += dp(m, n + 1);
	if (m > 1 && T[m - 1][n] < T[m][n]) //왼쪽
		sum += dp(m - 1, n);
	if (m < M && T[m + 1][n] < T[m][n]) //오른쪽
		sum += dp(m + 1, n);

	return ret=sum;
}

int main(void) {
	cin >> M >> N;
	//초기값 세팅
	memset(D, -1, sizeof(D));
	D[M][N] = 1;
	for (int m = 1; m <= M; m++) 
		for (int n = 1; n <= N; n++) 
			cin >> T[m][n];
	dp(1,1);
	/*for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			if (D[m][n]==-1) {
				cout << "0 ";
				continue;
			}
			cout << D[m][n]<<" ";
		}
		cout << '\n';
	}*/
	cout << D[1][1];
}

//https://www.acmicpc.net/problem/1520
