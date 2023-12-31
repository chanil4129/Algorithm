#include <bits/stdc++.h>
using namespace std;

int a, b, c;
priority_queue<int> q;

int main() {
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            return 0;
        }
        q.push(a);
        q.push(b);
        q.push(c);
        
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        c=q.top();
        q.pop();

        if(a>=b+c){
            cout<<"Invalid\n";
        } else if(a==b&&b==c){
            cout<<"Equilateral\n";
        } else if(a==b||b==c||a==c){
            cout<<"Isosceles\n";
        } else{
            cout<<"Scalene\n";
        }
    }
}