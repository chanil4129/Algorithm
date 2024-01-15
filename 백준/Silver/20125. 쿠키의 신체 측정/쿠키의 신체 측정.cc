#include <bits/stdc++.h>
using namespace std;

int n;
char M[1123][1123];
int xans, yans;
int laans, raans, bans, llans, rlans;

int main(void) {
    cin >> n;
    int i;
    int j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> M[i][j];
        }
    }
    int headx;
    bool isHeadFind = false;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (M[i][j] == '*') {
                isHeadFind = true;
                headx = i;
                break;
            }
        }
        if (isHeadFind) {
            break;
        }
    }
    // 심장
    xans = i + 1;
    yans = j;

    // 왼쪽팔
    for (j = yans - 1; j > 0; j--) {
        if (M[xans][j] == '*') {
            laans++;
        } else {
            break;
        }
    }

    // 오른쪽팔
    for (j = yans + 1; j <= n; j++) {
        if (M[xans][j] == '*') {
            raans++;
        } else {
            break;
        }
    }

    // 허리
    for (i = xans + 1; i <= n; i++) {
        if (M[i][yans] == '*') {
            bans++;
        } else {
            break;
        }
    }

    // 왼쪽다리
    for (i = xans + bans + 1; i <= n; i++) {
        if (M[i][yans - 1] == '*') {
            llans++;
        } else {
            break;
        }
    }

    // 오른쪽다리
    for (i = xans + bans + 1; i <= n; i++) {
        if (M[i][yans + 1] == '*') {
            rlans++;
        } else {
            break;
        }
    }

    cout << xans << " " << yans << "\n";
    cout << laans << " " << raans << " ";
    cout << bans << " ";
    cout << llans << " " << rlans;
}
