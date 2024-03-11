#include <bits/stdc++.h>
using namespace std;

int n, k;
string input;
bool ham[21234];
int ans;

int main(void) {
    cin >> n >> k >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'P') {
            int idx = i - k;
            if (idx < 0) {
                idx = 0;
            }
            while (idx <= i + k && idx < input.length()) {
                if (input[idx] == 'H' && ham[idx] == 0) {
                    ans++;
                    ham[idx] = 1;
                    break;
                }
                idx++;
            }
        }
    }
    cout << ans;
}