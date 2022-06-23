#include <iostream>
using namespace std;

int main(void) {
	int T;//Testcase
	int x1, y1, x2, y2;//시작점, 끝점의 좌표
	int n;
	int cx, cy, r;//n개의 원
	int count;//카운팅

	cin >> T;
	for (int i = 0; i < T; i++) {
		count = 0;//0으로 초기화
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cx >> cy >> r;
			//시작점 혹은 끝점이 하나는 밖에 하나는 안에 있으면 카운팅
			if ((r * r > (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) && r * r < (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) ||
				(r * r < (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) && r * r >(x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)))
				count++;
		}
		cout << count << "\n";

	}
}

//https://www.acmicpc.net/problem/1004