#include <iostream>
using namespace std;

int main(void) {
	int T, A, B;
	ios::sync_with_stdio(false);		//C++과 C 표준 스트림 동기화 해제
	cin.tie(NULL);		//입출력 연결 끊어주기
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";		//\n은 단순 개행. endl은 출력 버퍼를 비우는 역할까지 함.
	}
	return 0;
}

//https://www.acmicpc.net/problem/15552