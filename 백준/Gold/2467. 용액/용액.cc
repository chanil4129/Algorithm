#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> v;
pair<long long, long long> ans;
long long min_s;

int main(void) {
    cin >> n;
    long long input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    ans = {v[0], v[n - 1]};
    min_s = abs(v[0] + v[n - 1]);
    int left = 0;
    int right = n - 1;
    for (int i = 0; i < n - 2; i++) {
        if (abs(v[left] + v[right - 1]) < abs(v[left + 1] + v[right])) {
            right--;
        } else {
            left++;
        }
        if (min_s > abs(v[left] + v[right])) {
            ans = {v[left], v[right]};
            min_s = abs(v[left] + v[right]);
        }
    }
    cout << min(ans.first, ans.second) << " " << max(ans.first, ans.second);
}