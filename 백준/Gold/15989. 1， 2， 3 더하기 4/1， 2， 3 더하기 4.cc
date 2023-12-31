#include <bits/stdc++.h>
using namespace std;

int t, n;
int init[3][3] = {1, 1, 1, 0, 1, 1, 0, 0, 1};
int d[4][11234];

int main() {
    // init
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            d[i + 1][j + 1] = init[i][j];
        }
    }

    // dp
    for(int i=4;i<=10000;i++){
        d[1][i]=1;
        d[2][i]=i/2;
        d[3][i]=d[1][i-3]+d[2][i-3]+d[3][i-3];
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout<<d[1][n]+d[2][n]+d[3][n]<<"\n";
    }
}