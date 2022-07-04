#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long d[91];

long long f(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;

	long long& ref = d[n];
	if (ref != -1) return ref;

	return ref=f(n - 1) + f(n - 2);
}

//long long f(int n) {
//	d[1] = 1;
//	d[2] = 1;
//	for (int i = 3; i <= n; i++)
//		d[i] = d[i - 1] + d[i - 2];
//	return d[n];
//}

int main(void) {
	int N;
	cin >> N;
	memset(d, -1, sizeof(d));
	cout << f(N);
}

//https://www.acmicpc.net/problem/2193