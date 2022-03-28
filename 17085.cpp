#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char Map[16][16];

bool check(int sx, int sy, int k){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(i == k/2 || j == k/2){
                if(Map[i+sx][j+sy] != '#') return false;
                Map[i+sx][j+sy] = '*';
            }
        }
    }
    return true;
}

void go(int sx, int sy, int cnt, int res){
    if(cnt == 2){
        ans = max(ans, res);
        return;
    }
    char tmp[16][16];
    memcpy(tmp, Map, sizeof(Map));
    for(int i=sx;i<n;i++){
        if(i > sx) sy = 0;
        for(int j=sy;j<m;j++){
            for(int k=1;k<=min(n, m);k+=2){
                if(check(i, j, k)){
                    go(i, j+1, cnt+1, res*(2*k-1));
                }
                memcpy(Map, tmp, sizeof(tmp));
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    go(0, 0, 0, 1);
    cout << ans;
}