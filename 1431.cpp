#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <string> v;

int sum(string a) {		//숫자 합 sum 구하기
	int n = a.length(), sum = 0;
	for (int i = 0; i < n; i++) if (a[i] - '0' >= 0 && a[i] - '0' <= 9) sum += a[i] - '0';		//유니코드 빼주기
	return sum;
}

bool compare(string a, string b) {
	//길이 짧은순 정렬
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else {
		//숫자합 작은순 정렬
		int asum = sum(a);
		int bsum = sum(b);
		if (asum < bsum) return 1;
		else if (asum > bsum) return 0;
		//사전순 정렬
		else return a < b;
	}
}

int main(void) {
	cin >> n;		//개수 입력
	string input;		//기타번호 입력
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);		//벡터에 넣기
	}
	sort(v.begin(), v.end(), compare);		//정렬
	for (int i = 0; i < n; i++) cout << v[i] << endl;		//출력
	return 0;
}

//https://www.acmicpc.net/problem/1431
//https://chanshare.tistory.com/64