#include <bits/stdc++.h>
using namespace std;

int n, m;
bool block[501][501];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int cnt;
        cin >> cnt;
        for(int j=n;j>n-cnt;j--){
            block[j][i] = 1;
        }
    }
    int ans = 0;
    for(int i=n;i>0;i--){
        for(int j=1;j<=m;j++){
            if(block[i][j]) {
                int cnt = 0;
                for(int k=j-1;k>0;k--){
                    if(block[i][k]) {
                        ans += cnt;
                        break;
                    }
                    cnt++;
                }
            }
        }
    }
    cout << ans;
}