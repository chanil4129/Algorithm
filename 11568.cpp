#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int c;//card number
vector<int>::iterator low;//lower_bound index
vector<int> v;

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		low = lower_bound(v.begin(), v.end(), c); //lower_bound 위치 찾기
		if (low-v.begin() == v.size()) //마지막 index이면 그대로 삽입
			v.push_back(c);
		else //다른 index면 교환하기
			v[low-v.begin()] = c;
	}
	cout << v.size();
}

//https://www.acmicpc.net/problem/11568