#include <bits/stdc++.h>
using namespace std;

int n, k, ans, crime[17], r[17][17];
bool dead[17];

void go(int cnt, int alive){
    if(dead[k] || alive == 1){
        ans = max(ans, cnt);
        return;
    }

    if(alive % 2 == 0){
        for(int i=0;i<n;i++){
            if(i == k) continue;
            if(!dead[i]){
                dead[i] = 1;
                for(int j=0;j<n;j++){
                    if(!dead[j] && i != j){
                        crime[j] += r[i][j];
                    }
                }
                go(cnt+1, alive-1);
                for(int j=0;j<n;j++){
                    if(!dead[j] && i != j){
                        crime[j] -= r[i][j];
                    }
                }
                dead[i] = 0;
            }
        }
    } else {
        int idx, mx = -987654321;
        for(int i=0;i<n;i++){
            if(!dead[i] && mx < crime[i]){
                mx = crime[i];
                idx = i;
            }
        }
        dead[idx] = 1;
        go(cnt, alive-1);
        dead[idx] = 0;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> crime[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> r[i][j];
    }
    cin >> k;
    go(0, n);
    cout << ans;
}