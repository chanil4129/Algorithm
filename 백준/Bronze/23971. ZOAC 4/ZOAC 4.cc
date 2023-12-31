#include <bits/stdc++.h>
using namespace std;

int h,w,n,m;

int main(){
    cin>>h>>w>>n>>m;
    int row=h/(n+1);
    if(h%(n+1)){
        row++;
    }
    int column=w/(m+1);
    if(w%(m+1)){
        column++;
    }
    cout<<row*column;
}