#include <iostream>
using namespace std;

int check[51][51];    //배추 심은 곳 좌표
int M, N;   //(가로 길이),(세로 길이)

void backtrack(int x, int y) {
    //체크 했으므로 2로 바꾸기
    if (check[y][x] == 1) check[y][x] = 2;
    //상하좌우 백트래킹
    if (x > 0 && check[y][x - 1] == 1) backtrack(x - 1, y);   //왼쪽
    if (x < M - 1 && check[y][x + 1] == 1) backtrack(x + 1, y);   //오른쪽
    if (y > 0 && check[y - 1][x] == 1) backtrack(x, y - 1);   //위쪽
    if (y < N - 1 && check[y + 1][x] == 1) backtrack(x, y + 1);   //아래쪽
}

int main(void) {
    int T;    //Test case
    int K, X, Y;    //X, Y 좌표 입력
    int count;    //지렁이 수

    cin >> T;
    for (int t = 0; t < T; t++) {
        count = 0;    //Test 마다 지렁이 수 초기화
        cin >> M >> N >> K;   //M, N, K 입력
        //배열 초기화
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) check[n][m] = 0;
        //X,Y 입력
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            check[Y][X] = 1;
        }
        //backtracking
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) if (check[n][m] == 1) {   //백트레킹 할 때마다 지렁이수++
            count++;
            backtrack(m, n);
        }
        //출력
        cout << count << "\n";
    }
    return 0;
}

//https://www.acmicpc.net/problem/1012