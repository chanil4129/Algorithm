#include <bits/stdc++.h>
using namespace std;

int N, M;
int MAP[222][222];
vector<int> v;
int prt[222];  // parent
int hit[222];  // hight

int find_root(int x) {
    if (x == prt[x]) {
        return x;
    }
    return prt[x] = find_root(prt[x]);
}

void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);

    if (x != y) {
        if (hit[x] < hit[y]) {
            prt[x] = y;
        } else {
            if (hit[x] == hit[y]) {
                hit[x]++;
            }
            prt[y] = x;
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }
    int input;
    for (int i = 0; i < M; i++) {
        cin >> input;
        v.push_back(input);
    }
    for (int i = 1; i <= N; i++) {
        prt[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (MAP[i][j]) {
                union_root(i, j);
            }
        }
    }
    int root = find_root(v[0]);
    for (int i = 1; i < v.size(); i++) {
        if (root != find_root(v[i])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
