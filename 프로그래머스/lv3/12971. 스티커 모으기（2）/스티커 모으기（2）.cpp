#include <bits/stdc++.h>
using namespace std;

int d1[111111];
int d2[111111];

int solution(vector<int> sticker)
{    
    int ans=0;
    if(sticker.size()<=3){
        for(int i=0;i<sticker.size();i++){
            ans=max(ans,sticker[i]);
        }
        return ans;
    }

    //첫번재 스티커 X
    d1[1]=sticker[1];
    d1[2]=max(d1[1],sticker[2]);
    for(int i=3;i<sticker.size();i++){
        d1[i]=max(d1[i-2]+sticker[i],d1[i-1]);
    }
    
    //마지막 스티커 X
    int e=sticker.size()-1; //마지막 index
    d2[e-1]=sticker[e-1];
    d2[e-2]=max(d2[e-1],sticker[e-2]);
    for(int i=3;i<sticker.size();i++){
        d2[e-i]=max(d2[e+2-i]+sticker[e-i],d2[e+1-i]);
    }

    return max(d1[e],d2[0]);
}