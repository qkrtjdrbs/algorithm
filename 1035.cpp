#include <bits/stdc++.h>
using namespace std;

char Map[6][6];
int visited[1 << 26], cnt;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
queue<int> q;

int coord2Idx(int x, int y){
    return x*5 + y;
}

pair<int, int> idx2Coord(int idx){
    return {idx/5, idx%5};
}

bool isOnePiece(int state){
    int res=0;
    bool check[6][6];
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    for(int i=0;i<25;i++){
        if(state & (1 << i)){
            auto [x, y] = idx2Coord(i);
            q.push({x, y});
            check[x][y] = 1;
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                res++;
                for(int j=0;j<4;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || check[nx][ny]) continue;
                    if(state & (1 << coord2Idx(nx, ny))){
                        q.push({nx, ny});
                        check[nx][ny] = 1;
                    }
                }
            }
            return res == cnt ? true : false;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int start = 1 << 25;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> Map[i][j];
            if(Map[i][j] == '*'){
                start |= (1 << coord2Idx(i, j));
                cnt++;
            }
        }
    }
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int state = q.front();
        q.pop();
        if(isOnePiece(state)){
            cout << visited[state]-1;
            return 0;
        }
        for(int i=0;i<25;i++){
            if(state & (1 << i)){
                auto [x, y] = idx2Coord(i);
                for(int j=0;j<4;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    int nstate = state;
                    int nidx = coord2Idx(nx, ny);
                    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if(state & (1 << nidx)) continue;
                    nstate &= ~(1 << i);
                    nstate |= (1 << nidx);
                    if(visited[nstate]) continue;
                    q.push(nstate);
                    visited[nstate] = visited[state] + 1;
                }
            }
        }
    }
}