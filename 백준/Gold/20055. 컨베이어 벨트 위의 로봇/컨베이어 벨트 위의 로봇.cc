#include <bits/stdc++.h>
using namespace std;

int n, k;
int durability[222];
vector<int> robot_location;
deque<int> dq;
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        cin >> durability[i];
        dq.push_back(i);
    }

    while (true) {
        // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.
        int target = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (durability[i] == 0) {
                target++;
            }
        }
        if (target >= k) {
            cout << ans;
            return 0;
        }
        ans++;

        // 컨베이어 벨트 일
        // 1.벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
        // 올리는 곳
        int up = dq.back();
        dq.pop_back();
        dq.push_front(up);
        // 내리는 곳
        int down;
        if (up < n) {
            down = n + up - 1;
        } else {
            down = up - n - 1;
            if (down == -1) {
                down = 2 * n - 1;
            }
        }
        if (!robot_location.empty() && down == robot_location[0]) {
            robot_location.erase(robot_location.begin());
        }

        /* 2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한
        칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며,그 칸의
        내구도가 1 이상 남아 있어야한다.
        */
        for (int i = 0; i < robot_location.size(); i++) {
            int robot_next_iter = robot_location[i] + 1;
            if (robot_next_iter == 2 * n) {
                robot_next_iter = 0;
            }
            if (durability[robot_next_iter] > 0 &&
                (i == 0 || robot_location[i - 1] != robot_next_iter)) {
                durability[robot_next_iter]--;
                robot_location[i] = robot_next_iter;
            }
        }
        if (!robot_location.empty() && down == robot_location[0]) {
            robot_location.erase(robot_location.begin());
        }

        /*3.올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을
        올린다. */
        if (durability[up] > 0) {
            robot_location.push_back(up);
            durability[up]--;
        }
    }
}