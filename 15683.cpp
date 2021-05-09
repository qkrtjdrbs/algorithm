#include <bits/stdc++.h>
using namespace std;
int Map[9][9], n, m, ans=64;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void monitor(int dirX, int dirY, int i, int j){
    if(dirX != -1){
        int nx = i + dx[dirX];
        while(0 <= nx && nx < n && Map[nx][j] != 6){
                if(Map[nx][j] == 0){
                    Map[nx][j] = 7;
                }
                nx += dx[dirX];
        }
    }
    if(dirY != -1){
        int ny = j + dy[dirY];
        while(0 <= ny && ny < m && Map[i][ny] != 6){
                if(Map[i][ny] == 0){
                    Map[i][ny] = 7;
                }
                ny += dy[dirY];
        }
    }
}

void go(int x, int y){
    int tmp[9][9];
    for(int i=x;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == x && j < y) continue;
            if(1 <= Map[i][j] && Map[i][j] <= 5){
                memcpy(tmp, Map, sizeof(Map));
                switch (Map[i][j])
                {
                case 1:
                    {
                        for(int k=0;k<4;k++){
                            monitor(k, k, i, j);
                            go(i, j+1);
                            memcpy(Map, tmp, sizeof(Map));
                        } 
                        return;
                    }
                case 2:
                    /* left right */
                    {
                        monitor(-1, 0, i, j);
                        monitor(-1, 1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));
                        /* up down */
                        monitor(2, -1, i, j);
                        monitor(3, -1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));
                        return;
                    }
                case 3:
                    {
                        monitor(2, 0, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(2, 1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(3, 0, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(3, 1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));
                        return;
                    }
                case 4:
                    {
                        monitor(2, 0, i, j);
                        monitor(-1, 1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(2, 0, i, j);
                        monitor(3, -1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(3, 1, i, j);
                        monitor(-1, 0, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));

                        monitor(3, 1, i, j);
                        monitor(2, -1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));
                        return;
                    }  
                case 5:
                    {
                        monitor(2, 0, i, j);
                        monitor(3, 1, i, j);
                        go(i, j+1);
                        memcpy(Map, tmp, sizeof(Map));
                        return;
                    }
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]==0){
                ++res;
            }
        }
    }
    ans = min(ans, res);
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    }
    go(0, 0);
    cout << ans;
}