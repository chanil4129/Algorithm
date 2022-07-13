#include <iostream>
using namespace std;

int arr[31] = { 1,0,3 };

int f(int n) {
	if (n % 2) return 0;
	if (arr[n] != 0) return arr[n];
	int result = 3 * f(n - 1);
	for (int i = 3; i < n; i++) if(i%2==0) result += 2 * f(n - i);
	return arr[n] = result;
}

int main(void) {
	int N;
	cin >> N;
	cout << f(N);
}