#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;		//(정점 개수),(간선 개수)
int node_info[10001];		//정점들간의 연결 정보(일부만 이용)

class Edge {		//간선 정보(간선과 연결된 두 정점, 비용, 정렬 기준 등)
public:
	int node[2], cost;		//(간선과 연결된 두 정점), (비용)
	Edge(int a, int b, int cost) {		//초기화
		this->node[0] = a;
		this->node[1] = b;
		this->cost = cost;
	}
	bool operator <(Edge& edge) {		//비용을 기준으로 정렬
		return this->cost < edge.cost;
	}
};

int find(int a) {		//정점들끼리의 연결 정보 찾기(꼭대기에 있는 정점)
	if (node_info[a] == a) return a;
	return node_info[a] = find(node_info[a]);
}

void merge(int a, int b) {		//정점들끼리 연결하기
	a = find(a);
	b = find(b);
	if (a < b) node_info[b] = a;		//작은수를 넣는다.
	else node_info[a] = b;
}

int main(void) {
	int A, B, C, sum = 0;		//(정점1),(정점2),(비용),(출력할 sum값)
	vector<Edge> v;		//간성 정보에 대한 벡터
	cin >> V >> E;		//입력
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;		//입력
		v.push_back(Edge(A, B, C));		//초기화
	}
	sort(v.begin(), v.end());		//비용기준으로 정렬
	for (int i = 0; i < V; i++) node_info[i] = i;		//노드 정보 초기화(연결 아무것도 없다면 자기 자신 저장)
	for (int i = 0; i < v.size(); i++) {
		int a = find(v[i].node[0] - 1);		//a의 꼭대기 정점 찾기
		int b = find(v[i].node[1] - 1);		//b의 꼭대기 정점 찾기
		if (a == b) continue;		//같다면 연결 되어 있다는 뜻이므로 pass
		merge(v[i].node[0] - 1, v[i].node[1] - 1);		//연결 되어 있지 않으므로 합치기
		sum += v[i].cost;		//비용 더해주기
	}
	cout << sum;		//비용 출력
	return 0;
}

//https://www.acmicpc.net/problem/1197