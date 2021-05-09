#include <bits/stdc++.h>
using namespace std;
int n, m, ans, Map[51][51], cloud[51][51];
int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1,0,-1};
vector<pair<int, int>> inc;

void move(int dir, int dist){
    vector<pair<int, int>> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cloud[i][j] == 1){
                int nx = i + dx[dir]*dist;
                int ny = j + dy[dir]*dist;
                if(nx < 1){
                    if(abs(nx) < n)
                        nx = n + nx;
                    else
                        nx = n + (nx % n);
                } else if(nx > n){
                    nx = (nx % n);
                    if(nx == 0) nx = n;
                }
                if(ny < 1){
                    if(abs(ny) < n)
                        ny = n + ny;
                    else
                        ny = n + (ny % n);
                } else if(ny > n){
                    ny = (ny % n);
                    if(ny == 0) ny = n;
                }
                cloud[i][j] = 0;
                t.push_back({nx, ny});
            }
        }
    }
    while(!t.empty()){
        int x, y;
        tie(x, y) = t.back();
        cloud[x][y] = 1;
        t.pop_back();
    }
}

void raining(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cloud[i][j] == 1){
                ++Map[i][j];
                inc.push_back({i, j});
                cloud[i][j] = 0;
            }
        }
    }
}

void waterCopyBug(){
    for(auto X : inc){
        int x, y, cnt=0;
        tie(x, y) = X;
        for(int k=2;k<=8;k+=2){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
            if(Map[nx][ny])
                ++cnt;
        }
        Map[x][y] += cnt;
    }
}

bool findInc(int i, int j){
    for(auto X : inc){
        int x, y;
        tie(x, y) = X;
        if(x == i && y == j)
            return true;
    }
    return false;
}

void makeCloud(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Map[i][j] >= 2){
                if(!findInc(i, j)){
                    cloud[i][j] = 1;
                    Map[i][j] -= 2;
                }
            }
        }
    }
    inc.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == n || i == n-1){
                if(j == 1 || j == 2)
                    cloud[i][j] = 1;
            }
            cin >> Map[i][j];
        }
    }
    for(int i=0;i<m;i++){
        int dir, dist;
        cin >> dir >> dist;
        move(dir, dist);
        raining();
        waterCopyBug();
        makeCloud();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans += Map[i][j];
        }
    }
    cout << ans;
}