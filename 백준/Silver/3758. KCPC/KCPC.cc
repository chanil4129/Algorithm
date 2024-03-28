#include <bits/stdc++.h>
using namespace std;

int TEST;
int N, K, T, M;
int s[111][111];
int cnt[111];
int seq[111];
vector<pair<int, pair<int, pair<int, int>>>> v;
// 팀번호, 최종점수, 제출 횟수, 마지막 제출 시간

bool fun(pair<int, pair<int, pair<int, int>>> a,
         pair<int, pair<int, pair<int, int>>> b) {
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    } else {
        return a.second.first > b.second.first;
    }
}

int main(void) {
    cin >> TEST;
    while (TEST--) {
        cin >> N >> K >> T >> M;
        memset(s, 0, sizeof(s));
        memset(cnt, 0, sizeof(cnt));
        fill(seq, seq + 111, 123456789);
        int a, b, c;
        for (int m = 1; m <= M; m++) {
            cin >> a >> b >> c;
            s[a][b] = max(s[a][b], c);
            cnt[a]++;
            seq[a] = m;
        }
        for (int i = 1; i <= N; i++) {
            int score = 0;
            for (int j = 1; j <= K; j++) {
                score += s[i][j];
            }
            v.push_back({i, {score, {cnt[i], seq[i]}}});
        }
        sort(v.begin(), v.end(), fun);
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first == T) {
                cout << i + 1 << "\n";
                break;
            }
        }
        v.clear();
    }
}