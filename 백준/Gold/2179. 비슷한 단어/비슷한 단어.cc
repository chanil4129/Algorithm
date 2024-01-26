#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;
map<string, pair<int, int>> ms;

int main(void) {
    string input;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }
    for (int a = 0; a < v.size(); a++) {
        string sb = "";
        for (int i = 0; i < v[a].length(); i++) {
            sb += v[a][i];
            // cout << sb << "\n";
            if (ms.find(sb) == ms.end()) {
                ms[sb] = {1, a};
            } else {
                ms[sb].first++;
            }
        }
    }
    string maxS;
    int seq = 21234;
    for (auto iter = ms.begin(); iter != ms.end(); iter++) {
        // cout << iter->first << " " << iter->second.first << " "
        //      << iter->second.second << "\n";
        if (iter->first.length() >= maxS.length() && iter->second.first >= 2) {
            if (iter->first.length() == maxS.length() &&
                iter->second.second > seq) {
            } else {
                maxS = iter->first;
                seq = iter->second.second;
            }
        }
    }
    // cout << "###" << maxS << "\n";
    int printCnt = 0;
    for (auto s : v) {
        if (s.find(maxS) == 0) {
            cout << s << "\n";
            printCnt++;
            if (printCnt == 2) {
                return 0;
            }
        }
    }
}
