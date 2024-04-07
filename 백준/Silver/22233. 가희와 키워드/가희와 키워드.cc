#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> memo;
vector<string> tokens;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    string input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        memo.insert({input, 0});
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        stringstream sstream(input);
        string token;
        tokens.clear();
        while (getline(sstream, token, ',')) {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size(); i++) {
            if (memo.find(tokens[i]) != memo.end()) {
                memo.erase(tokens[i]);
            }
        }
        cout << memo.size() << "\n";
    }
}