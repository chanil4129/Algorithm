#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int member[1111];
int score[1111];
int five[1111];
int ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int input;

    cin >> T;
    while (T--) {
        vector<int> v;
        unordered_map<int, int> candidate;
        cin >> n;
        memset(member, 0, sizeof(member));
        memset(score, 0, sizeof(score));
        memset(five, 0, sizeof(five));
        for (int i = 0; i < n; i++) {
            cin >> input;
            member[input]++;
            if (member[input] == 5) {
                five[input] = i;
            }
            v.push_back(input);
        }
        for (int i = 1; i <= 1000; i++) {
            if (member[i] == 6) {
                candidate[i] = 0;
            }
        }
        int plus = 1;
        for (int i = 0; i < v.size(); i++) {
            int team = v[i];
            if (candidate.find(team) != candidate.end()) {
                if (candidate[team] < 4) {
                    score[team] += plus;
                }
                candidate[team]++;
                plus++;
            }
        }
        int min = 1123456789;
        ans = 0;
        for (int i = 1; i <= 1000; i++) {
            if (candidate.find(i) != candidate.end() && min > score[i]) {
                min = score[i];
                ans = i;
            }
            if (candidate.find(i) != candidate.end() && min == score[i]) {
                if (five[ans] > five[i]) {
                    min = score[i];
                    ans = i;
                }
            }
        }
        cout << ans << "\n";
    }
}