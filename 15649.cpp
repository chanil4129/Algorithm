#include <iostream>
using namespace std;

int N, M;   //입력
int check[10];    //출력할 배열(index마다 출력할 값 넣기)
bool promising[10] = {};    //유망한지 확인(0이 유망), 0으로 초기화

void backtrack(int level) {   //상태공간 트리의 level
    if (level == M) {   //level이 M이면 출력
        for (int i = 0; i < M; i++) cout << check[i] << " ";
        cout << "\n";
    }
    //1부터 N까지 노드들을 전부 확인하는데 backtracking을 사용
    else for (int i = 1; i <= N; i++) if (promising[i] == 0) {    //유망하다면
        promising[i] = true;    //다음에 중복되지 않게
        check[level] = i;   //출력배열에 값 넣기              
        backtrack(level + 1);   //backtracking
        promising[i] = false;   //뒤로 돌아오기 위함      
    }
}

int main(void) {
    cin >> N >> M;    //입력
    backtrack(0);   //backtraking
}