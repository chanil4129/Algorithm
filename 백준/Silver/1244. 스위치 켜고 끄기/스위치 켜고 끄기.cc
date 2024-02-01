#include <bits/stdc++.h>
using namespace std;

int n, m;
bool sw[111];
vector<pair<int, int>> v;

void reverse(int i) {
    if (sw[i]) {
        sw[i] = false;
    } else {
        sw[i] = true;
    }
}

void man(int a) {
    for (int i = a; i <= n; i = i + a) {
        reverse(i);
    }
}

void woman(int a) {
    int left = a - 1;
    int right = a + 1;
    reverse(a);
    while (left >= 1 && right <= n && sw[left] == sw[right]) {
        reverse(left--);
        reverse(right++);
    }
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sw[i];
    }
    cin >> m;
    int sex, num;
    for (int i = 0; i < m; i++) {
        cin >> sex >> num;
        v.push_back({sex, num});
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == 1) {
            man(v[i].second);
        } else {
            woman(v[i].second);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << sw[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
}
