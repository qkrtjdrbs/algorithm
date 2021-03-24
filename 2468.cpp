#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], Visit[101][101], ans;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

void dfs(int x, int y){
    Visit[x][y] = 1;
    for(int i=0;i<4;i++){
        int sx, sy;
        sx = x + dx[i];
        sy = y + dy[i];
        if(0 <= sx && sx < n && 0 <= sy && sy < n){
            if(!Visit[sx][sy]){
                dfs(sx, sy);
            }
        }
    }
}

void flood(int height){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Visit[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]<=height){
                Visit[i][j] = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    for(int h=0;h<=100;h++){
        int tmp = 0;
        flood(h);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!Visit[i][j]){
                    tmp += 1;
                    dfs(i, j);
                }
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}