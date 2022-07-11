#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x[1000001];
vector<int> v;

//binary search(정렬된 상태만 가능)
//int bin_search(int target,int low,int high) {
//	//종료
//	if (low > high) return -1;
//	//탐색
//	int mid = (low + high) / 2;
//	if (v[mid] == target) { //찾는 값이 나온다면
//		cout << mid << " ";
//		return mid;
//	}
//	else if (v[mid] > target) //찾는 값보다 크다면
//		return bin_search(target, low, mid - 1);
//	else //찾는 값보다 작다면
//		return bin_search(target, mid + 1, high);
//}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end()); //벡터 정렬
	//정렬된 벡터에서 중복된 값을 제거(unique는 중복값을 뒤로 보냄. 뒤로 보낸 중복값을 삭제)
	v.erase(unique(v.begin(), v.end()), v.end()); 
	for (int i = 0; i < N; i++)
		//bin_search(x[i],0,v.size());
		cout<<lower_bound(v.begin(), v.end(), x[i])-v.begin()<<" "; //lower_bound를 통한 이진탐색
}

//https://www.acmicpc.net/problem/18870