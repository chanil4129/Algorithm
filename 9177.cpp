#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s1, s2, tgt;
string ans;
int d[444][444];

int f(int left, int right) {
	//종료검사
	int cur = left + right;
	if (cur == s1.length() + s2.length()) {
		return 1;
	}
	//중복검사
	int& ref = d[left][right];
	if (ref != -1) return ref;
	//
	if (s1[left] == tgt[cur]) {
		if(f(left + 1, right)) return ref=1;

	}
	if (s2[right] == tgt[cur]) {
		if(f(left, right + 1)) return ref=1;
	}
	return ref=0;
}

int main(void) {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> s1 >> s2 >> tgt;
		memset(d, -1, sizeof(d));
		if (f(0, 0)) ans = "yes";
		else ans = "no";
		cout << "Data set " << i << ":" << ans<<"\n";
	}
}