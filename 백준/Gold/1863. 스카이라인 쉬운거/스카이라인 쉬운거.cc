#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
stack<int> st;

int main(void) {
    cin >> n;
    int x;
    int y;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (st.top() != -1) {
            while (st.top() > y) {
                ans++;
                st.pop();
            }
            if (st.top() < y) {
                st.push(y);
            }
        } else {
            st.push(y);
        }
    }
    while (st.top() > 0) {
        ans++;
        st.pop();
    }
    cout << ans;
}
