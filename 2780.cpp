#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int D[1001][10];
int ans;

void dp(int n) {
	//초기값 세팅
	for (int i = 0; i < 10; i++) D[1][i] = 1;
	//점화식
	for (int i = 2; i <= n; i++) {
		D[i][0] = D[i - 1][7]; //0일때
		D[i][1] = D[i - 1][2] + D[i - 1][4]; //1일때
		D[i][2] = D[i - 1][1] + D[i - 1][3] + D[i - 1][5]; //2일때
		D[i][3] = D[i - 1][2] + D[i - 1][6]; //3일때
		D[i][4] = D[i - 1][1] + D[i - 1][5] + D[i - 1][7]; //4일때
		D[i][5] = D[i - 1][2] + D[i - 1][4] + D[i - 1][6] + D[i - 1][8]; //5일때
		D[i][6] = D[i - 1][3] + D[i - 1][5] + D[i - 1][9]; //6일때
		D[i][7] = D[i - 1][0] + D[i - 1][4] + D[i - 1][8]; //7일때
		D[i][8] = D[i - 1][5] + D[i - 1][7] + D[i - 1][9]; //8일때
		D[i][9] = D[i - 1][6] + D[i - 1][8]; //9일때
		for (int j = 0; j < 10; j++) D[i][j] = D[i][j] % 1234567; //너무 커질 수 있으므로 1234567 mod
	}
	ans = 0;
	//제일 뒷 번호가 0~9일때 모든 경우를 다 더해준 것이 답
	for (int i = 0; i < 10; i++) ans = (ans + D[n][i]) % 1234567;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		dp(N);
		cout << ans << '\n';
	}
}

//https://www.acmicpc.net/problem/2780