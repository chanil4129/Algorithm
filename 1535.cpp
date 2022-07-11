#include <iostream>
#include <algorithm>
using namespace std;

int L[21], J[21];
int d[21][101];

void dp(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 100; j++) {
			if (L[i] >= j) d[i][j] = d[i - 1][j];
			else d[i][j] = max(d[i - 1][j], d[i - 1][j - L[i]] + J[i]);
		}
	}
}

int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> L[i];
	for (int i = 1; i <= N; i++)
		cin >> J[i];
	dp(N);
	cout << d[N][100];
}

//https://www.acmicpc.net/problem/1535