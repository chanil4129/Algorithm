#include <bits/stdc++.h>
using namespace std;

char MAP[3][3];

bool condition(char c) {
    for (int i = 0; i < 3; i++) {
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            if (MAP[i][j] != c) {
                valid = false;
            }
        }
        if (valid) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        bool valid = true;
        for (int j = 0; j < 3; j++) {
            if (MAP[j][i] != c) {
                valid = false;
            }
        }
        if (valid) {
            return true;
        }
    }
    if (MAP[0][0] == c && MAP[1][1] == c && MAP[2][2] == c) {
        return true;
    }
    if (MAP[0][2] == c && MAP[1][1] == c && MAP[2][0] == c) {
        return true;
    }
    return false;
}

int main(void) {
    char s[10];
    while (true) {
        scanf("%s", s);
        if (!strcmp(s, "end")) {
            return 0;
        }
        int ocnt = 0;
        int xcnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                MAP[i][j] = s[i * 3 + j];
                if (MAP[i][j] == 'O') {
                    ocnt++;
                } else if (MAP[i][j] == 'X') {
                    xcnt++;
                }
            }
        }

        bool isValid = false;
        if (xcnt - ocnt == 1) {  // x승리
            isValid = condition('X') && !condition('O');
        } else if (xcnt - ocnt == 0) {  // o승리
            isValid = condition('O') && !condition('X');
        }
        if (xcnt == 5 && ocnt == 4) {  // 9개를 다 쓴 경우
            isValid = !condition('O');
        }
        isValid ? printf("valid\n") : printf("invalid\n");
    }
}
