#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1111];
char s1[1111], s2[1111];
int ans;

int main(void) {
	int i, j;
	int cnt;
	cin >> s1 >> s2;
	for (i = 0; s1[i]; i++) {
		cnt = 0;
		for (j = 0; s2[j]; j++) {
			if (cnt < d[j])
				cnt = d[j];
			else if (s1[i] == s2[j])
				d[j] = cnt + 1;
			ans = max(ans, d[j]);
		}
	}
	cout << ans;
}