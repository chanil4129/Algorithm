#include <iostream>
using namespace std;

//조건 : 5 이하의 자연수

int main(void) {
	int arr[40] = {		//정렬할 배열
		1,2,4,5,3,2,1,4,5,2,
		1,3,5,1,2,3,4,5,1,1,
		2,3,3,2,5,5,1,4,1,2,
		3,4,4,2,3,5,4,1,4,1
	};
	int sort[6] = {};		//계수 정렬을 하기 위한 배열. 0으로 초기화. index는 1~5까지만 사용(index 0은 사용x)
	for (int i = 0; i < 40; i++) sort[arr[i]]++;		//배열을 참조 할 때마다 그와 동일한 index값을 +1한다.
	for (int i = 1; i <= 5; i++) while (sort[i]--) cout << i << " ";		//그 개수만큼 출력
	return 0;
}