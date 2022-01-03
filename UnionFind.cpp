#include <iostream>
using namespace std;

int get_parent(int v[], int x) {		//부모 V를 구한다, 작은 값을 갖도록함.
	if (v[x] == x) return x;
	return v[x] = get_parent(v, v[x]);
}

void union_parent(int v[], int x, int y) {		//V 연결하기. 
	x = get_parent(v, x);		
	y = get_parent(v, y);
	if (x < y) v[y] = x;		//더 작은값을 가지도록
	else v[x] = y;
}

void find_parent(int v[], int x, int y) {		//연결되어 있는지 확인
	x = get_parent(v, x);
	y = get_parent(v, y);
	if (x == y) cout<<"connected";
	else cout<<"not_connected";
}

int main(void) {
	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = i;
	//1~4까지 연결, 5~9까지 연결
	union_parent(arr, 1, 2);
	union_parent(arr, 2, 3);
	union_parent(arr, 3, 4);
	union_parent(arr, 5, 6);
	union_parent(arr, 6, 7);
	union_parent(arr, 7, 8);
	union_parent(arr, 8, 9);
	cout << "1과 9 연결관계 : ";
	find_parent(arr,1,9);		//1~4까지 연결되어 있고, 5~9까지만 연결되어 있음.
	//연결 후
	union_parent(arr, 4, 5);		//4,5 연결
	cout << "\n1과 9 연결관계 : ";
	find_parent(arr, 1, 9);		//4,5가 연결되면 1~9까지 모두 연결된다.
}