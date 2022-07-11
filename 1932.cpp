#include <iostream>
#include <algorithm>
using namespace std;

int t[501][501]; //table 데이터
int d[501][501]; //dynamic 배열
int ans;

void dp(int n) {
	//초기값 세팅
	d[1][1] = t[1][1];
	//점화식 
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
	//가장 큰 값 찾기
	for (int i = 1; i <= n; i++) if (ans < d[n][i]) ans = d[n][i];
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> t[i][j];
	dp(n);
	cout << ans;
}

//https://www.acmicpc.net/problem/1932