#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, Map[51][51], v[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void go(int x, int y){
    v[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!v[nx][ny] && Map[nx][ny]){
            go(nx, ny);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                v[i][j] = 0;
                Map[i][j] = 0;
            }
        }
        for(int i=0;i<k;i++){
            int x, y;
            cin >> y >> x;
            Map[x][y] = 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j] && !v[i][j]){
                    go(i, j);
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}