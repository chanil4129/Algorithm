#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> load;
vector<long long> city;
vector<long long> price;
int ans;

int main(void) {
    cin >> n;
    long long input;
    for (int i = 1; i < n; i++) {
        cin >> input;
        load.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        cin >> input;
        city.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        price.push_back(0);
    }
    price[0] += load[0] * city[0];
    int left = 0;
    int right = 1;
    while (right < n) {
        if (city[left] >= city[right]) {
            left = right;
        }
        price[right] += city[left] * load[right];
        right++;
    }
    for (int i = 0; i < n; i++) {
        ans += price[i];
    }
    cout << ans;
    // 마지막 기름
}