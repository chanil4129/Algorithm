#include <bits/stdc++.h>
#define INF 123456789
using namespace std;

int n, s;
vector<int> a;
int num;
int ans = INF;

int main(void) {
    cin >> n >> s;
    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        a.push_back(input);
    }
    int left = 0;
    int right = 0;
    int acu = a[0];
    num++;
    if (acu >= s) {
        cout << 1;
        return 0;
    }
    while (right < n) {
        num++;
        acu += a[++right];
        while (acu >= s) {
            ans = min(ans, num);
            num--;
            acu -= a[left++];
        }
    }
    if (ans == INF) {
        cout << 0;
        return 0;
    }
    cout << ans;
}
