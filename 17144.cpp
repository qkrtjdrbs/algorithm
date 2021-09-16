#include <bits/stdc++.h>
using namespace std;
int r, c, t, Map[51][51], airX;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void spreadOut(vector<tuple<int, int, int>> &info){
    while(!info.empty()){
        int x, y, dust;
        tie(x, y, dust) = info.back();
        info.pop_back();
        int dir = 0;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(Map[nx][ny] == -1 || nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if(dust / 5 == 0) break;
            Map[nx][ny] += dust / 5;
            ++dir;
        }
        dust /= 5;
        Map[x][y] -= dir * dust;
    }
}

void rotate(){
    int tmp[51][51];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tmp[i][j] = Map[i][j]; 
        }
    }
    for(int i=0;i<=airX-1;i++){
        for(int j=0;j<c;j++){
            if(i == 0){
                if(j == 0)
                    Map[i+1][j] = tmp[i][j];
                else
                    Map[i][j-1] = tmp[i][j];
            } else if(i == airX-1){
                if(j == 0){
                    Map[i][j+1] = 0;
                } else if(0 < j && j < c-1){
                    Map[i][j+1] = tmp[i][j]; 
                } else if(j == c-1){
                    Map[i-1][j] = tmp[i][j];
                }
            } else {
                if(j == 0){
                    if(Map[i+1][j] != -1){
                        Map[i+1][j] = tmp[i][j];
                    }
                } else if(j == c-1){
                    Map[i-1][j] = tmp[i][j];
                }
            }
        }
    }
    for(int i=airX;i<r;i++){
        for(int j=0;j<c;j++){
            if(i == airX){
                if(j == 0){
                    Map[i][j+1] = 0;
                } else if(0 < j && j < c-1){
                    Map[i][j+1] = tmp[i][j]; 
                } else if(j == c-1){
                    Map[i+1][j] = tmp[i][j];
                }
            } else if(i == r-1){
                if(j == 0)
                    Map[i-1][j] = tmp[i][j];
                else
                    Map[i][j-1] = tmp[i][j];
            } else {
                if(j == 0){
                    if(Map[i-1][j] != -1){
                        Map[i-1][j] = tmp[i][j];
                    }
                } else if(j == c-1){
                    Map[i+1][j] = tmp[i][j];
                }
            }
        }
    }
}

int main(){
    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> Map[i][j];    
        }
    }
    while(t--){
        vector<tuple<int, int, int>> info;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(Map[i][j] != 0 && Map[i][j] != -1){
                    info.push_back({i, j, Map[i][j]});
                }
                if(Map[i][j] == -1){
                    airX = i;
                }
            }  
        }
        spreadOut(info);
        rotate();
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(Map[i][j] != -1){
                ans += Map[i][j];
            }
        }  
    }
    cout << ans;
}