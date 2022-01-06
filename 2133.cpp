#include <iostream>
using namespace std;

int n;

//int arr[2][31];
//
//int f(int n) {    //점화식 : f(n) = 3*f(n-2) + ( 2*f(n-4) + 2*f(n-6) + ... +2*f(0) )
//	//초기값 설정
//	arr[0][2] = 3;
//	arr[1][4] = 1;
//	arr[0][4] = 11;
//	if (n % 2) return 0;    //홀수면 0 리턴
//	for (int i = 5; i <= n; i++) {		//짝수면 점화식대로
//		if (n % 2 == 0) {
//			arr[1][i] = arr[0][i - 4] + arr[1][i - 2];
//			arr[0][i] = 3 * arr[0][i - 2] + 2 * arr[1][i];
//		}
//	}
//	return arr[0][n];   //배열값 리턴
//}

int arr[31] = { 1,0,3 };

int f(int n) {    //점화식 : f(n) = 3*f(n-2) + ( 2*f(n-4) + 2*f(n-6) + ... +2*f(0) )
	if (n % 2) return 0;    //홀수면 0 리턴
	if (arr[n] != 0) return arr[n];   //짝수일 때 0이 아닌 값이면 그 배열값 리턴
	int result = 3 * f(n - 2);    //점화식 구할 때, 앞에 3*f(n-2) 부분
	for (int i = 3; i <= n; i++) if (i % 2 == 0) result += 2 * f(n - i);    //점화식 구할 때 나머지 뒷부분
	return arr[n] = result;   //배열값 리턴
}

int main(void) {
	int n;
	cin >> n;   //입력
	cout << f(n);   //출력
}

//https://www.acmicpc.net/problem/2133