#include <bits/stdc++.h>
using namespace std;

int n, b, w;
string road;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> b >> w;
    cin >> road;
    int l=0, r=0, ans=0, bCnt=0, wCnt=0;
    road[0] == 'W' ? wCnt++ : bCnt++;
    while(1){
        if(bCnt <= b && wCnt >= w){
            ans = max(ans, r-l+1);
        }
        if(bCnt > b){
            if(l+1 >= n) break;
            if(road[l++] == 'B') bCnt--;
            else wCnt--;
        } else {
            if(r+1 < n && road[++r] == 'W') wCnt++;
            else bCnt++;
        }
    }
    cout << ans;
}