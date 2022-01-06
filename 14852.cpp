#include <iostream>
using namespace std;

long long arr[2][1000001];

long long f(int n) {
	//배열값 초기값 설정
	arr[0][0] = 0;
	arr[0][1] = 2;
	arr[0][2] = 7;
	arr[1][2] = 1;
	//점화식 : f(n) = 2*f(n-1) + 3*f(n-2) + (2*f(n-3) + 2*f(n-4) + ... + 2*f(0))
	for (int i = 3; i <= n; i++) {
		arr[1][i] = (arr[1][i - 1] + arr[0][i - 3]) % 1000000007;
		arr[0][i] = (2 * arr[0][i - 1] + 3 * arr[0][i - 2] + 2 * arr[1][i]) % 1000000007;
	}
	return arr[0][n];
}

int main(void) {
	int n;
	cin >> n;		//입력
	cout << f(n);		//출력
	return 0;
}

//https://www.acmicpc.net/problem/14852