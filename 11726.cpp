#include <iostream>
using namespace std;

int n;
int arr[1001] = { 0,1,2 };

int f(int n) {		//동적 계획법으로 구현
	if (arr[n] != 0) return arr[n];
	return arr[n] = (f(n - 1) + f(n - 2)) % 10007;
}

int main(void) {
	cin >> n;
	cout << f(n);
	return 0;
}

//https://www.acmicpc.net/problem/11726