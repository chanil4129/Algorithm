#include <bits/stdc++.h>
using namespace std;

int n;
string target;
int dic[26];
int ans;

int main(void) {
    cin >> n >> target;
    for (auto c : target) {
        dic[c - 'A']++;
    }

    string input;
    for (int i = 1; i < n; i++) {
        cin >> input;
        int inputDic[26];
        memset(inputDic, 0, sizeof(inputDic));
        for (auto c : input) {
            inputDic[c - 'A']++;
        }
        int t = 0;
        for (int j = 0; j < 26; j++) {
            int diff = dic[j] - inputDic[j];
            if (abs(diff) == 1) {
                t++;
            } else if (abs(diff) > 1) {
                t += 100;
            }
        }
        if (t <= 2 && abs((int)input.length() - (int)target.length()) <= 1) {
            ans++;
        }
    }
    cout << ans;
}