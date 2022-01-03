#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;		//(정점 수),(간선 수)

class Edge {		//간선과 연결된 정점 2개와 비용 등의 정보
public:
	int node[2];		//연결된 정점
	int cost;		//비용
	Edge(int a, int b, int c) {		//초기화
		this->node[0] = a;
		this->node[1] = b;
		this->cost = c;
	}
	bool operator <(Edge& edge) {		//정렬 기준
		return this->cost < edge.cost;		//비용이 작은순
	}
};

//Union-Find
int get_parent(int node[], int a) {		//부모 정보 얻기
	if (node[a] == a) return a;
	return node[a] = get_parent(node, node[a]);
}

bool find_node(int node[],int a, int b) {		//정점 a,b가 연결되어 있는지 확인
	a = get_parent(node, a);
	b = get_parent(node, b);
	if (a == b) return true;		//연결되면 true
	else return false;		//연결 안되어있으면 false
}

void union_node(int node[], int a, int b) {		//정점 a,b 연결하기
	a = get_parent(node, a);
	b = get_parent(node, b);
	if (a < b) node[b] = a;		//더 작은 값 넣기	
	else node[a] = b;
}

int main(void) {
	int a, b, c, sum = 0;		//입력 받는 a,b,c 그리고 출력할 sum. sum은 0으로 초기화
	int* node;		//node의 연결 정보를 담을 배열 
	cin >> n >> m;		//입력
	vector<Edge> v;		//간선 vector
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;		//입력
		v.push_back(Edge(a, b, c));		//간선 정보 넣기
	}
	sort(v.begin(), v.end());		//간선을 비용대로 정렬
	node = new int[n];		//node 동적 할당
	for (int i = 0; i < n; i++) node[i] = i;		//아무것도 연결되어 있지 않다면 자기자신을 가리킴
	for (int i = 0; i < v.size(); i++) {
		if (!find_node(node, v[i].node[0] - 1, v[i].node[1] - 1)) {		//해당 edge와 node가 연결 안되어 있다면
			union_node(node, v[i].node[0] - 1, v[i].node[1] - 1);		//두 node 연결
			sum += v[i].cost;		//비용 더해주기
		}
	}
	cout << sum;		//비용 출력
	delete[] node;		//node 할당 해제
	return 0;
}

//https://www.acmicpc.net/problem/1922