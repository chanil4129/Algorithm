#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> maxQ;
priority_queue<int, vector<int>, greater<int>> minQ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int input;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (maxQ.size() == minQ.size()) {
            maxQ.push(input);
        } else {
            minQ.push(input);
        }
        if (!maxQ.empty() && !minQ.empty() && maxQ.top() > minQ.top()) {
            int maxTop = maxQ.top();
            int minTop = minQ.top();
            maxQ.pop();
            minQ.pop();
            maxQ.push(minTop);
            minQ.push(maxTop);
        }
        cout << maxQ.top() << "\n";
    }
}