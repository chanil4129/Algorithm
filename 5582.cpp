#include <iostream>
using namespace std;

int d[4444][4444];
char s1[4444], s2[4444];
int ans;

int main(void) {
	cin >> s1 + 1 >> s2 + 1;
	int i, j;
	for (i = 1; s1[i]; i++) {
		for (j = 1; s2[j]; j++) {
			if(s1[i]==s2[j]) d[i][j] = d[i - 1][j - 1] + 1;
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans;
}