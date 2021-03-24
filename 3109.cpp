#include <bits/stdc++.h>
using namespace std;
int r, c, ans, visit[10001][501];
int dx[] = {-1, 0, 1}; 
int dy[] = {1, 1, 1};
string b[10001];
bool flag = false;

void dfs(int x, int y){
    visit[x][y] = 1;
    if(y == c-1){
        flag = true;
        return;
    }
    else{
        for(int i=0;i<3;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && !visit[nx][ny] && b[nx][ny] == '.')
                dfs(nx, ny);
            if(flag)
                return;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> b[i];
    }
    for(int i=0;i<r;i++){
        flag = false;
        dfs(i, 0);
        if(flag)
            ans += 1;
    }
    cout << ans;
}
