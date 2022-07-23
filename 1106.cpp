#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 111111

int C, N;
int a, b; //a:홍보할 때 드는 비용. b:그 비용으로 얻을 수 있는 고객의 수
int d[MAX]; //DP table. index는 비용. D[index]는 비용당 가능한 최대 인원

int main(void) {
	cin >> C >> N;
	int i, j;
	for (i = 1; i <= N; i++) {
		cin >> a >> b;
		for (j = a; j <= MAX; j++) {
			d[j] = max(d[j], d[j - a] + b);
		}
	}
	for (i = 1; i <= MAX; i++) {
		if (d[i] >= C) {
			cout << i;
			exit(0);
		}
	}
}

//https://www.acmicpc.net/problem/1106