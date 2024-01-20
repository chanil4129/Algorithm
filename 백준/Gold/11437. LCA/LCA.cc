#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[51234];
int dep[51234];
bool flag[51234];
int parentNode[51234];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int node1, node2;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> node1 >> node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    queue<pair<int, int>> q;
    dep[1] = 0;
    q.push({1, 0});
    flag[1] = true;
    while (!q.empty()) {
        int parent = q.front().first;
        int parentDep = q.front().second;
        q.pop();
        for (int i = 0; i < v[parent].size(); i++) {
            int child = v[parent][i];
            if (!flag[child]) {
                parentNode[child] = parent;
                flag[child] = true;
                dep[child] = parentDep + 1;
                q.push({child, parentDep + 1});
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        int dep1 = dep[node1];
        int dep2 = dep[node2];
        while (dep1 < dep2) {
            node2 = parentNode[node2];
            dep2--;
        }
        while (dep2 < dep1) {
            node1 = parentNode[node1];
            dep1--;
        }
        while (node1 != node2) {
            node1 = parentNode[node1];
            node2 = parentNode[node2];
        }
        cout << node1 << "\n";
    }
}
