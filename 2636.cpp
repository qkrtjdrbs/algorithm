#include <bits/stdc++.h>
using namespace std;
int n, m, meltTime=0, cnt=0, Map[101][101], Visit[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int, int>> face;

void faceBf(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!Visit[nx][ny]){
            Visit[nx][ny] = 1;
            face.push_back({nx, ny});
        }
    }
}

void go(int x, int y){
    Visit[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!Visit[nx][ny] && !Map[nx][ny]){
            go(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 1) ++cnt;
        }
    }
    while(1){
        go(0, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!Map[i][j] && Visit[i][j]){
                    faceBf(i, j);
                }
            }
        }
        int size = face.size();
        if(cnt - size == 0){
            break;
        } else {
            cnt -= size;
            while(!face.empty()){
                int x, y;
                tie(x, y) = face.back();
                face.pop_back();
                Map[x][y] = 0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Visit[i][j] = 0;
            }
        }
        ++meltTime;
    }
    cout << meltTime+1 << '\n' << cnt;
}