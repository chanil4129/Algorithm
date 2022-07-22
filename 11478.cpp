#include <iostream>
#include <set>
using namespace std;

set<string> u;

int main(void) {
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		string str = ""; //빈문자열
		for (int j = i; j < S.size(); j++) {
			str += S[j]; //원소 생성
			cout << str << "\n";
			u.insert(str); //set에 원소를 넣으면 unique한 값만 남게됨
		}
	}
	cout << u.size();
}

//https://www.acmicpc.net/problem/11478