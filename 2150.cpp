#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;		//(정점 개수),(간선/규칙 개수)
int id,d[10001];		//(고유번호),(부모 번호)
bool finished[10001];		//(썼는지 체크용)
vector<int> node[10001];		//인접노드 정보
vector<vector<int>> SCC;		//SCC - 강한 결합 요소(Strongly Connected Component). 사이클 한묶음씩 그에 대한 정보를 담고 있음
stack<int> s;		//스택

int dfs(int x) {
	d[x] = ++id;		//부모 번호
	s.push(x);		//노드 push
	int parent = d[x];		//부모 번호(비교를 위한)
	for (int i = 0; i < node[x].size(); i++) {		//인접노드들을 살피며
		int y = node[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));		//dfs로 탐색하며 사이클 발생할 때 parent에 최솟값
		else if (finished[y] == 0) parent = min(parent, d[y]);		//체크 안된거 즉 사이클 발생시 parent(최솟값)값 넣기
	}
	if (parent == d[x]) {		//부모 번호가 처음 자기 자신과 같게 가진다면 스택에 있는 사이클 번호들 빼기
		vector<int> scc;		//사이클 하나
		while (1) {
			int t = s.top();		//top 정보 t에 저장
			s.pop();		//pop
			scc.push_back(t);		//top 정보 넣기
			finished[t] = true;		//사이클 하나 체크했으므로 true로 만들기
			if (t == x) break;		//본인 노드가 나온다면 break
		}
		SCC.push_back(scc);		//사이클 하나를 SCC에 저장
	}
	return parent;
}

int main(void) {
	int A, B;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		node[A].push_back(B);		//인접 노드 정보 저장
	}
	for (int i = 1; i <= V; i++) if (d[i] == 0) dfs(i);		//체크 안한 노드들 dfs
	for (int i = 0; i < SCC.size(); i++) sort(SCC[i].begin(), SCC[i].end());		//사이클의 노드들 오름차순
	sort(SCC.begin(), SCC.end());		//사이클들의 첫번째 번호를 기준으로 오름차순
	cout << SCC.size() << "\n";		//사이클의 개수
	for (int i = 0; i < SCC.size(); i++) {		//사이클들
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << " ";		//한 사이클의 노드들 출력
		cout << "-1\n";
	}
	return 0;
}

//https://www.acmicpc.net/problem/2150