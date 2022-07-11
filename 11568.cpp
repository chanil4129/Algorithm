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
		low = lower_bound(v.begin(), v.end(), c);
		if (low-v.begin() == v.size())
			v.push_back(c);
		else
			v[low-v.begin()] = c;
	}
	cout << v.size();
}

//https://www.acmicpc.net/problem/11568