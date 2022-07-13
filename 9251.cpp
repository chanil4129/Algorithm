#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char s1[1111], s2[1111];
int d[1111][1111];
int i, j;

int main(void) {
	cin >> s1 + 1 >> s2 + 1;
	for (i = 1; s1[i]; i++) {
		for (j = 1; s2[j]; j++) {
			//if (s1[i] == s2[j])
			//	d[i][j] = d[i - 1][j - 1] + 1;
			//else
			//	d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			d[i][j] = max({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] + (s1[i] == s2[j]) }); //배열을 넘겨 max 값 구할 수 있음
		}
	}
	cout << d[i - 1][j - 1];
}

//https://www.acmicpc.net/problem/9251