#include <bits/stdc++.h>
using namespace std;

class Player {
   public:
    int level;
    string name;
    bool isPlay;

    Player() {
        level = 0;
        name = "";
        isPlay = false;
    }

    Player(int a, string b) {
        level = a;
        name = b;
        isPlay = false;
    }

    void playing() { isPlay = true; }
};

int P, M;
int L;
string N;
Player player[333];

bool fun(const pair<int, string> a, const pair<int, string> b) {
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> P >> M;
    for (int i = 0; i < P; i++) {
        cin >> L >> N;
        player[i] = Player(L, N);
    }
    for (int i = 0; i < P; i++) {
        Player p = player[i];
        if (player[i].isPlay == true) {
            continue;
        }
        player[i].playing();
        vector<int> room;
        room.push_back(i);
        for (int j = i + 1; j < P; j++) {
            if (room.size() == M) {
                break;
            }
            Player comp = player[j];
            if (comp.isPlay == false && p.level + 10 >= comp.level &&
                p.level - 10 <= comp.level) {
                room.push_back(j);
                player[j].playing();
            }
        }
        if (room.size() == M) {
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }
        vector<pair<int, string>> room_output;
        for (int a = 0; a < room.size(); a++) {
            room_output.push_back(
                {player[room[a]].level, player[room[a]].name});
        }
        sort(room_output.begin(), room_output.end(), fun);
        for (int a = 0; a < room_output.size(); a++) {
            cout << room_output[a].first << " " << room_output[a].second
                 << "\n";
        }
    }
}