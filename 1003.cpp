#include <iostream>
using namespace std;

int T, n;       //(Test case),(호출)
int result[41] = { 1,0,1 };     //n을 기준으로 index n은 0의 출력 개수, index n+1은 1의 출력 개수

void fibonacci(int n) {     
    for (int i = 3; i <= n + 1; i++) result[i] = result[i - 1] + result[i - 2];     //앞의 두값을 더해주면 됨
}

int main(void) {
    cin >> T;       //Test case 입력
    for (int i = 0; i < T; i++) {
        cin >> n;       //n 입력
        fibonacci(n);       //피보나치
        cout << result[n] << " " << result[n + 1] << endl;      //출력
    }
}

//https://www.acmicpc.net/problem/1003