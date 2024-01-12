#include <bits/stdc++.h>
using namespace std;

int n;
bool src[112345];
bool dst[112345];
int ans;

void switching(bool t[], int i) {
    if (i == 0) {
        t[i + 1] = !t[i + 1];
    } else if (i == n - 1) {
        t[i - 1] = !t[i - 1];
    } else {
        t[i + 1] = !t[i + 1];
        t[i - 1] = !t[i - 1];
    }
    t[i] = !t[i];
}

bool isSame(bool a[], bool b[]) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &src[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &dst[i]);
    }

    if (n <= 2) {
        if (isSame(src, dst)) {
            printf("0");
            return 0;
        }
        switching(src, 0);
        if (isSame(src, dst)) {
            printf("1");
            return 0;
        }
        printf("-1");
        return 0;
    }

    // 첫번째 전구 스위치를 누르고 시작
    bool f1[112345];
    int c1 = 1;
    memcpy(f1, src, sizeof(bool) * n);
    f1[0] = !f1[0];
    f1[1] = !f1[1];
    for (int i = 1; i < n; i++) {
        if (dst[i - 1] != f1[i - 1]) {
            switching(f1, i);
            c1++;
        }
    }

    // 첫번째 전구 스위치를 누르지 않고 시작
    bool f2[112345];
    int c2 = 0;
    memcpy(f2, src, sizeof(bool) * n);
    for (int i = 1; i < n; i++) {
        if (dst[i - 1] != f2[i - 1]) {
            switching(f2, i);
            c2++;
        }
    }

    bool first = false;
    bool second = false;
    if (isSame(f1, dst)) {
        first = true;
    }
    if (isSame(f2, dst)) {
        second = true;
    }
    if (first && second) {
        printf("%d", min(c1, c2));
        return 0;
    } else if (first) {
        printf("%d", c1);
        return 0;
    } else if (second) {
        printf("%d", c2);
        return 0;
    }
    printf("-1");
    return 0;
}