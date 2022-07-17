//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//char s1[1111], s2[1111];
//int d[1111][1111];
//int i, j;
//
//int main(void) {
//	cin >> s1 + 1 >> s2 + 1;
//	for (i = 1; s1[i]; i++) {
//		for (j = 1; s2[j]; j++) {
//			//if (s1[i] == s2[j])
//			//	d[i][j] = d[i - 1][j - 1] + 1;
//			//else
//			//	d[i][j] = max(d[i][j - 1], d[i  - 1][j]);
//			d[i][j] = max({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] + (s1[i] == s2[j]) }); //배열을 넘겨 max 값 구할 수 있음
//		}
//	}
//	cout << d[i - 1][j - 1];
//}

//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1111];
char s1[1111], s2[1111];
int ans;

int main(void) {
	int i, j;
	int flag;
	cin >> s1 >> s2;
	for (i = 0; s1[i]; i++) {
		flag = 0;
		for (j = 0; s2[j]; j++) {
			if (flag < d[j]) flag = d[j];
			else if (s1[i] == s2[j]) d[j] = flag + 1;
			ans = max(ans, d[j]);
		}
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/9251