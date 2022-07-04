#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x[1000001];
vector<int> v;

int bin_search(int target,int low,int high) {
	if (low > high) return -1;
	int mid = (low + high) / 2;
	if (v[mid] == target) {
		cout << mid << " ";
		return mid;
	}
	else if (v[mid] > target)
		return bin_search(target, low, mid - 1);
	else
		return bin_search(target, mid + 1, high);
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++)
		bin_search(x[i],0,v.size());
}

//https://www.acmicpc.net/problem/18870