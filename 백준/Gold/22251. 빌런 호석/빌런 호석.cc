#include <bits/stdc++.h>
using namespace std;

int n, k, p, x;
/*
     0
   1   2
     3
   4   5
     6
*/
bool dig[10][7] = {
    {true, true, true, false, true, true, true},      // 0
    {false, false, true, false, false, true, false},  // 1
    {true, false, true, true, true, false, true},     // 2
    {true, false, true, true, false, true, true},     // 3
    {false, true, true, true, false, true, false},    // 4
    {true, true, false, true, false, true, true},     // 5
    {true, true, false, true, true, true, true},      // 6
    {true, false, true, false, false, true, false},   // 7
    {true, true, true, true, true, true, true},       // 8
    {true, true, true, true, false, true, true}       // 9
};
int digConvert[10][10];
int ans;

int convertDig(int src, int dst) {
    int result = 0;
    for (int i = 0; i < 7; i++) {
        if (dig[src][i] != dig[dst][i]) {
            result++;
        }
    }
    return result;
}

int main(void) {
    cin >> n >> k >> p >> x;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            digConvert[i][j] = convertDig(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == x) {
            continue;
        }
        int target = i;
        int cur = x;
        int acu = 0;
        for (int ten = 0; ten < k; ten++) {
            acu += digConvert[cur % 10][target % 10];
            target /= 10;
            cur /= 10;
        }
        if (acu <= p) {
            ans++;
        }
    }
    cout << ans;
}
