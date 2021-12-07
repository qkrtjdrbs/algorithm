#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, dp[51][51][4];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[51][51];

bool check(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'S'){
                sx = i; sy = j;
            } else if(Map[i][j] == 'g'){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = i + dy[k];
                    if(check(nx, ny)) continue;
                    Map[nx][ny] = 'x';
                }
            }
        }
    }
}