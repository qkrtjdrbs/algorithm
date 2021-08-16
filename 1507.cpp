#include <bits/stdc++.h>
using namespace std;
int n, Map[21][21], Visit[21][21];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Map[i][j];
            Visit[i][j] = Map[i][j];
        }
    }
    int ans = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j || i == k || j == k) continue;
                if(Map[i][j] > Map[i][k] + Map[k][j]){
                    cout << -1;
                    return 0;
                }
                if(Map[i][j] == Map[i][k] + Map[k][j]){
                    Visit[i][j] = 0;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
            ans += Visit[i][j]; 
        } 
    }
    cout << ans / 2;
}