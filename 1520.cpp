#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T[501][501];
int ans[501][501];
int M, N;

int dp(int m,int n) {
	if (m == M && n == N) return 1;
	if (m < 1 || n < 1 || m > M || n > N) return 0;

	int &ret = ans[m][n];
	if (ret != -1) return ret;

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
	memset(ans, -1, sizeof(ans));
	ans[M][N] = 1;
	for (int m = 1; m <= M; m++) 
		for (int n = 1; n <= N; n++) 
			cin >> T[m][n];
	dp(1,1);
	/*for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++)
			cout << ans[m][n];
		cout << '\n';
	}*/
	cout << ans[1][1];
}

//https://www.acmicpc.net/problem/1520