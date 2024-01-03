#include <bits/stdc++.h>
using namespace std;

class StringGame {
   public:
    int number;
    vector<int> idx;
    int min_value;
    int max_value;
};

int t, k;
string w;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> w >> k;
        map<char, StringGame> info;
        for (char c = 'a'; c <= 'z'; c++) {
            StringGame sg;
            sg.number = 0;
            sg.min_value = 11234;
            sg.max_value = 0;
            info[c] = sg;
        }
        for (int idx = 0; idx < w.length(); idx++) {
            StringGame &sg = info[w[idx]];
            sg.number++;
            sg.idx.push_back(idx);
            if (sg.number >= k) {
                int diff = idx - sg.idx[sg.number - k] + 1;
                if (sg.min_value > diff) {
                    sg.min_value = diff;
                }
                if (sg.max_value < diff) {
                    sg.max_value = diff;
                }
            }
        }
        int isExist = 0;
        int third = 11234;
        int fourth = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (info[c].number >= k) {
                isExist = 1;
                if (third > info[c].min_value) {
                    third = info[c].min_value;
                }
                if (fourth < info[c].max_value) {
                    fourth = info[c].max_value;
                }
            }
        }
        if (isExist) {
            cout << third << " " << fourth << "\n";
        } else {
            cout << "-1\n";
        }
    }
}