#include <iostream>
#include <vector>
using namespace std;

int stairs[301];//계단의 cost
int ans[301];//계단의 누적 가중치. ans[n]이 답

void dp(int n) {
	//배열 초기값 설정
	ans[1] = stairs[1];
	ans[2] = stairs[1] + stairs[2];
	ans[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
	//an=an-3+bn+bn-3과 an=an-2+bn에서 더 큰값이 답
	for (int i = 4; i <= n; i++) 
		ans[i] = max(ans[i - 3] + stairs[i] + stairs[i - 1], ans[i - 2] + stairs[i]);
}

int main(void) {
	int n;//계단 수
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];
	dp(n);
	cout << ans[n];
}

//https://www.acmicpc.net/problem/2579