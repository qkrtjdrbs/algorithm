#include <bits/stdc++.h>
using namespace std;

int n, m, r, ans, Map[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char info[101][101];

int fall(int x, int y, char dir){
    int res=0, d;
    if(dir == 'E') d = 1;
    else if(dir == 'W') d = 0;
    else if(dir == 'S') d = 3;
    else d = 2;
    if(info[x][y] == 'S'){
        info[x][y] = 'F';
        res++;
    }
    for(int i=1;i<Map[x][y];i++){
        int nx = x + dx[d]*i;
        int ny = y + dy[d]*i;
        if(nx <= 0 || nx > n || ny <= 0 || ny > m) break;
        if(info[nx][ny] == 'S'){
            info[nx][ny] = 'F';
            res += 1 + fall(nx, ny, dir);
        }
    }
    return res;
}

void stand(int x, int y){
    info[x][y] = 'S';
}


int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> Map[i][j];
            info[i][j] = 'S';
        }
    }
    for(int i=0;i<r;i++){
        int x, y, xx, yy;
        char dir;
        cin >> x >> y >> dir >> xx >> yy;
        if(info[x][y] == 'S'){
            ans += fall(x, y, dir);
        }
        stand(xx, yy);
    }
    cout << ans << '\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << info[i][j] << ' ';
        }
        cout << '\n';
    }
}