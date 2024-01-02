#include <bits/stdc++.h>
using namespace std;

int p, t;
vector<int> v;

int fun() {
    int ans = 0;
    vector<int> sv = {v[0]};
    vector<int>::iterator it;

    for (int i = 1; i < v.size(); i++) {
        it = sv.begin();
        int j = 0;
        for (; j < sv.size(); j++) {
            if (sv[j] > v[i]) {
                break;
            }
        }
        int back = sv.size() - j;
        ans += back;
        sv.insert(it + j, v[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int input;
    cin >> p;
    for (int i = 1; i <= p; i++) {
        cin >> t;
        for (int j = 0; j < 20; j++) {
            cin >> input;
            v.push_back(input);
        }

        cout << t << " " << fun() << "\n";
        v.clear();
    }
}