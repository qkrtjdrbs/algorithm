#include <bits/stdc++.h>
using namespace std;
int n, m, a[51][51], ans;

void dfs(int sx, int sy, int sd, int cnt){
    if(cnt == 4){
        if(sd == 0){
            if(sx + 1 >= n || a[sx+1][sy]==1){
                return;
            } else {
                dfs(sx+1, sy, sd, 0);
            }
        } else if(sd == 3){
            if(sy + 1 >= m || a[sx][sy+1]==1){
            } else {
                dfs(sx, sy+1, sd, 0);
            }
        } else if(sd == 2){
            if(sx - 1 < 0 || a[sx-1][sy]==1){
            } else {
                dfs(sx-1, sy, sd, 0);
            }
        } else if(sd == 1){
            if(sy - 1 < 0 || a[sx][sy-1]==1){
            } else {
                dfs(sx, sy-1, sd, 0);
            }
        }
        return;
    }
    if(!a[sx][sy]) ans += 1;
    a[sx][sy] = 2;
    if(sd == 0){
        if(0 <= sy - 1){
            if(!a[sx][sy-1]){
                dfs(sx, sy-1, 3, 0);
            } else {
                dfs(sx, sy, 3, cnt+1);
            }
        }
    } else if(sd == 3){
        if(sx + 1 < n){
            if(!a[sx+1][sy]){
                dfs(sx+1, sy, 2, 0);
            } else {
                dfs(sx, sy, 2, cnt+1);
            }
        }
    } else if(sd == 2){
        if(sy + 1 < m){
            if(!a[sx][sy+1]){
                dfs(sx, sy+1, 1, 0);
            } else {
                dfs(sx, sy, 1, cnt+1);
            }
        }
    } else if(sd == 1){
        if(sx - 1 >= 0){
            if(!a[sx-1][sy]){
                dfs(sx-1, sy, 0, 0);
            } else {
                dfs(sx, sy, 0, cnt+1);
            }
        }
    }
}

int main(){
    int startx, starty, startd;
    cin >> n >> m >> startx >> starty >> startd;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    dfs(startx, starty, startd, 0);
    cout << ans;
}