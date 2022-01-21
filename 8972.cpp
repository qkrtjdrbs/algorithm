#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy;
int dx[] = {0,1,1,1,0,0,0,-1,-1,-1};
int dy[] = {0,-1,0,1,-1,0,1,-1,0,1};
char Map[101][101];
string command;

int dist(int x, int y, int xx, int yy){
    return abs(x-xx) + abs(y-yy);
}

bool moveI(int idx){
    int nx = sx + dx[idx];
    int ny = sy + dy[idx];
    if(Map[nx][ny] == 'R') return false;
    Map[sx][sy] = '.';
    Map[nx][ny] = 'I';
    sx = nx; sy = ny;
    return true;
}

bool moveR(){
    int tmp[101][101];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'R'){
                int mn = 987654321, dir;
                for(int k=1;k<=9;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(mn > dist(sx, sy, nx, ny)){
                        mn = dist(sx, sy, nx, ny);
                        dir = k;
                    }
                }
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(Map[nx][ny] == 'I') return false;
                Map[i][j] = '.';
                tmp[nx][ny]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j] == 1){
                Map[i][j] = 'R';
            }
        }
    }
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'I'){
                sx = i; sy = j;
            }
        }
    }
    cin >> command;
    for(int i=0;i<command.size();i++){
        if(!moveI(command[i]-'0')){
            cout << "kraj " << i+1;
            return 0;
        }
        if(!moveR()){
            cout << "kraj " << i+1;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Map[i][j];
        }
        cout << '\n';
    }
}