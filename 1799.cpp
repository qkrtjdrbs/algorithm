#include <bits/stdc++.h>
using namespace std;

int n, ans[2], Map[11][11], r[21], l[21];

void go(int x, int y, int cnt, bool flag){
    if(y >= n){
        x++;
        if(y % 2 == 0) y = 1;
        else y = 0;
    }

    if(x >= n){
        ans[flag] = max(ans[flag], cnt);
        return;
    }

    if(Map[x][y] && !l[y-x+n] && !r[x+y]){
        l[y-x+n] = r[x+y] = 1;
        go(x, y+2, cnt+1, flag);
        l[y-x+n] = r[x+y] = 0;
    }
    go(x, y+2, cnt, flag);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    go(0, 0, 0, 0);
    go(0, 1, 0, 1);
    cout << ans[0]+ans[1];
}