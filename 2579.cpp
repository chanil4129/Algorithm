#include <iostream>
using namespace std;

int stairs[301];
int ans;

void df() {

}

int main(void) {
	int n;//°è´Ü ¼ö
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stairs[i];
	df();
	cout << ans;
}