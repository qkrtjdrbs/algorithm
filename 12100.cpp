#include <bits/stdc++.h>
using namespace std;
int n, Map[21][21], ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int calMax(){
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res = max(res, Map[i][j]);
        }
    }
    return res;
}

void move(int i, int j, int k){
    int nx = i + dx[k];
    int ny = j + dy[k];
    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
        if(Map[i][j] == Map[nx][ny]){
            Map[nx][ny] *= -2;
            Map[i][j] = 0;
            return;
        } else if(Map[nx][ny] == 0){
            Map[nx][ny] = Map[i][j];
            Map[i][j] = 0;
            move(nx, ny, k);            
        } else if(Map[i][j] != Map[nx][ny]){
            return;
        }
    }
}

void go(int cnt){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Map[i][j] < 0)
                Map[i][j] *= -1;
        }
    }
    int tmp[21][21];
    memcpy(tmp, Map, sizeof(Map));
    if(cnt == 5){
        int res = calMax();
        ans = max(ans, res);
        return;
    }
    for(int k=0;k<4;k++){
        if(k == 0 || k == 2){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        move(i, j, k);
                    }
                }
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        move(i, j, k);
                    }
                }
            }
        }
        go(cnt+1);
        memcpy(Map, tmp, sizeof(tmp));
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    go(0);
    cout << ans;       
}