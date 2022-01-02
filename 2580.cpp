#include <iostream>
using namespace std;

int sdk[10][10] = {};		//스도쿠 판
bool row[10][10] = {}, column[10][10] = {}, square[10][10] = {};		//확인용으로 (행), (열), (3x3사각형). 첫번째 index는 순서대로 행, 열, 3x3사각형, 두번째 index에는 1~9값이 들어감으로 써 확인

void backtrack(int cnt) {		//81레벨로 모두 방문하는 트리, x,y 좌표라 생각하면 됨.
	int x = cnt / 9;		//x좌표
	int y = cnt % 9;		//y좌표
	if (cnt == 81) {		//스도쿠 판 출력
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << sdk[i][j] << " ";
			cout << endl;
		}
		exit(0);		//여러가지 답을 모두 출력하기 때문에 한번 출력하고 바로 끝내기 위해 무조건 필요함
	}
	else if (sdk[x][y] == 0) for (int i = 1; i <= 9; i++) {		//스도쿠 판에 0일 때만 1~9까지 노드를 필요로함
		if (!row[x][i] && !column[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {		//해당 행,열,3x3사각형 조건이 모두 false일때만
			sdk[x][y] = i;		//sdk에 값 넣기
			row[x][i] = true; column[y][i] = true; square[(x / 3) * 3 + (y / 3)][i] = true;		//해당 행,열,3x3 조건을 모두 true로 만든다
			backtrack(cnt + 1);		//백트래킹
			sdk[x][y] = 0;		//초기화
			row[x][i] = false; column[y][i] = false; square[(x / 3) * 3 + (y / 3)][i] = false;		//초기화
		}
	}
	else backtrack(cnt + 1);		//스도쿠 판에 0이 아니라면 그냥 넘어감
}

int main(void) {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {		//스도쿠판 입력
		cin >> sdk[i][j];
		if (sdk[i][j] != 0) {		//입력한 스도쿠판 값이 0이 아니라면 해당 행,열,3x3사각형값을 true로 바꾼다
			row[i][sdk[i][j]] = true;
			column[j][sdk[i][j]] = true;
			square[(i / 3) * 3 + (j / 3)][sdk[i][j]] = true;
		}
	}
	backtrack(0);		//백트래킹
	return 0;
}

//https://www.acmicpc.net/problem/2580