#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<int> v;
int ans;

int main(void) {
    cin >> h >> w;
    int input;
    for (int i = 0; i < w; i++) {
        cin >> input;
        v.push_back(input);
    }
    int left;
    int right;
    int height;
    for (int i = 1; i < v.size() - 1; i++) {
        left = 0;
        right = 0;
        for (int j = i; j >= 0; j--) {
            left = max(left, v[j]);
        }
        for (int j = i; j < v.size(); j++) {
            right = max(right, v[j]);
        }
        height = min(left, right);
        ans += height - v[i];
    }
    cout << ans;
}