#include <bits/stdc++.h>
#define MAX 10
using namespace std;

int n, ans, Map[11][11];
int dx[] = {1,0};
int dy[] = {0,1};

void go(int t, int x, int y){
    if(t == 1){
        for(int i=0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(1){
                if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || Map[nx][ny]){
                    nx -= dx[i];
                    ny -= dy[i];
                    Map[nx][ny] = 1;
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    } else if(t == 2){
        for(int i=0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(1){
                if(nx < 0 || nx >= MAX || ny+1 < 0 || ny+1 >= MAX || Map[nx][ny+1] || Map[nx][ny]){
                    nx -= dx[i];
                    ny -= dy[i];
                    Map[nx][ny] = 2;
                    Map[nx][ny+1] = 2;
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    } else {
        for(int i=0;i<2;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(1){
                if(nx+1 < 0 || nx+1 >= MAX || ny < 0 || ny >= MAX || Map[nx][ny] || Map[nx+1][ny]){
                    nx -= dx[i];
                    ny -= dy[i];
                    Map[nx][ny] = 3;
                    Map[nx+1][ny] = 3;
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
}

void down(){
    int i = MAX - 1;
    while(1){
        if(i < 6) break;
        int gCnt = 0;
        for(int j=0;j<4;j++){
            if(Map[i][j]) gCnt++;
        }
        if(gCnt == 4) {
            ans++;
            for(int j=0;j<4;j++) Map[i][j] = 0;
            for(int k=i-1;k>=4;k--){
                for(int j=0;j<4;j++){
                    swap(Map[k][j], Map[k+1][j]);
                }
            }
        } else i--;
    }
    i = MAX - 1;
    while(1){
        if(i < 6) break;
        int bCnt = 0;
        for(int j=0;j<4;j++){
            if(Map[j][i]) bCnt++;
        }
        if(bCnt == 4) {
            ans++;
            for(int j=0;j<4;j++) Map[j][i] = 0;
            for(int k=i-1;k>=4;k--){
                for(int j=0;j<4;j++){
                    swap(Map[j][k], Map[j][k+1]);
                }
            }
        } else i--;
    }
    int gCnt = 0, bCnt = 0;
    for(int i=4;i<6;i++){
        for(int j=0;j<4;j++){
            if(Map[i][j]){
                gCnt++;
                break;
            }
        }
    }
    for(int i=4;i<6;i++){
        for(int j=0;j<4;j++){
            if(Map[j][i]){
                bCnt++;
                break;
            }
        }
    }
    for(int i=MAX-1;i>=MAX-gCnt;i--){
        for(int j=0;j<4;j++) Map[i][j] = 0;
    }
    for(int i=0;i<4;i++){
        for(int j=MAX-1;j>=4;j--){
            if(Map[j][i]){
                swap(Map[j+gCnt][i], Map[j][i]);
            }
        }
    }
    for(int i=MAX-1;i>=MAX-bCnt;i--){
        for(int j=0;j<4;j++) Map[j][i] = 0;
    } 
    for(int i=0;i<4;i++){
        for(int j=MAX-1;j>=4;j--){
            if(Map[i][j]){
                swap(Map[i][j+bCnt], Map[i][j]);               
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int t, x, y;
        cin >> t >> x >> y;
        go(t, x, y);
        down();
    }
    cout << ans << '\n';
    int cnt = 0;
    for(int i=6;i<MAX;i++){
        for(int j=0;j<4;j++){
            if(Map[i][j]) cnt++;
            if(Map[j][i]) cnt++;
        }
    }
    cout << cnt;
}