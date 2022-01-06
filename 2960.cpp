#include <iostream>
#include <math.h>
using namespace std;

bool arr[1001];
int n, k, cnt = 0;

void primeNumberSieve() {
	for (int i = 2; i <= n; i++) for (int j = i; j <= n; j += i) {		//문제 조건의 에라토스테네스의 체
		if (arr[j] == true) continue;		//이미 지웠다면 넘어가기
		arr[j] = true;		//P 지우기(true값이 지운거임)
		cnt++;		//카운팅
		if (cnt == k) cout << j;		//k번째이면 출력
	}
	
}

int main(void) {
	cin >> n >> k;		//입력
	primeNumberSieve();		//에라토스테네스의 체 실행
	return 0;
}

//https://www.acmicpc.net/problem/2960