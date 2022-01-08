#include <iostream>
using namespace std;

const int INF = 1e9;		//INF 일경우는 정점이 연결이 안된 경우
const int number = 5;		//정점 개수

int a[5][5] = {		//정점들의 인접행렬
	{0,1,INF,1,5},
	{9,0,3,2,INF},
	{INF,INF,0,4,INF},
	{INF,INF,2,0,3},
	{3,INF,INF,INF,0}
};

void floyd() {		//floyd 알고리즘
	int d[number][number];		//새로운 인접행렬
	for (int i = 0; i < number; i++) for (int j = 0; j < number; j++) d[i][j] = a[i][j];		//정보 d에 옮겨 담기
	//k는 거쳐가는 정점, i는 시작 정점, j는 도착 정점
	for (int k = 0; k < number; k++) for (int i = 0; i < number; i++) for (int j = 0; j < number; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
	for (int i = 0; i < number; i++) {		//출력하기
		for (int j = 0; j < number; j++) cout << d[i][j] << " ";
		cout << "\n";
	}
}

int main(void) {
	floyd();		//플로이드 알고리즘
	return 0;
}