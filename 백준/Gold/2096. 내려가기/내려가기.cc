#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[3];
int dmax[3], dmin[3];
int pmax[3], pmin[3];  // 이전 3개

int main() {
    cin >> n;
    int input;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> input;
            v[j].push_back(input);
        }
    }

    // 초기화
    for (int i = 0; i < 3; i++) {
        pmax[i] = v[i][0];
        pmin[i] = v[i][0];
    }
    // DP
    for (int i = 1; i < n; i++) {
        dmax[0] = max(pmax[0], pmax[1]) + v[0][i];
        dmax[1] = max({pmax[0], pmax[1], pmax[2]}) + v[1][i];
        dmax[2] = max(pmax[1], pmax[2]) + v[2][i];
        pmax[0] = dmax[0];
        pmax[1] = dmax[1];
        pmax[2] = dmax[2];
        dmin[0] = min(pmin[0], pmin[1]) + v[0][i];
        dmin[1] = min({pmin[0], pmin[1], pmin[2]}) + v[1][i];
        dmin[2] = min(pmin[1], pmin[2]) + v[2][i];
        pmin[0] = dmin[0];
        pmin[1] = dmin[1];
        pmin[2] = dmin[2];
    }
    // 출력
    cout << max({pmax[0], pmax[1], pmax[2]}) << " "
         << min({pmin[0], pmin[1], pmin[2]});
}