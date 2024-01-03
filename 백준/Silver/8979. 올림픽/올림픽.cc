#include <bits/stdc++.h>
using namespace std;

class Medal {
   public:
    int c;
    int g;
    int s;
    int b;

    bool isJointRanking(const Medal& other) {
        if (g == other.g && s == other.s && b == other.b) {
            return true;
        }
        return false;
    }

    bool operator<(const Medal& other) const {
        if (g != other.g) return g > other.g;
        if (s != other.s) return s > other.s;
        return b > other.b;
    }
};

int n, k;
vector<Medal> v;

int main() {
    cin >> n >> k;
    int country, gold, silver, bronze;
    for (int i = 0; i < n; i++) {
        cin >> country >> gold >> silver >> bronze;
        Medal medal;
        medal.c = country;
        medal.g = gold;
        medal.s = silver;
        medal.b = bronze;
        v.push_back(medal);
    }
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i].c == k) {
            int j = 1;
            for (; i - j >= 0; j++) {
                if (!v[i].isJointRanking(v[i - j])) {
                    break;
                }
            }
            cout << i - j + 2;
            return 0;
        }
    }
}