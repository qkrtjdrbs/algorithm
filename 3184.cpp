#include <bits/stdc++.h>
using namespace std;

int n, m, counts[250*250][2], visited[251][251];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[251][251];

void counting(int x, int y, int z){
    if(Map[x][y] == 'o'){
        counts[z][0]++;
    } else if(Map[x][y] == 'v'){
        counts[z][1]++;
    }
}

void dfs(int x, int y, int z){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny] || Map[nx][ny] == '#') continue;
        visited[nx][ny] = z;
        counting(nx, ny, z);
        dfs(nx, ny, z);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    int c = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] != '#' && !visited[i][j]){
                visited[i][j] = c;
                counting(i, j, c);
                dfs(i, j, c++);
            }
        }
    }
    int sheep=0, wolf=0;
    for(int i=0;i<c;i++){
        if(counts[i][0] > counts[i][1]){
            sheep += counts[i][0];
        } else {
            wolf += counts[i][1];
        }
    }
    cout << sheep << " " << wolf;
}