#include <bits/stdc++.h>
using namespace std;
int n, ans=987654321, m[51][51], v[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] = 987654321;
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    v[0][0] = 0;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
    
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;           
            if(m[nx][ny] == 1){
                if(v[nx][ny] > v[x][y]){
                    v[nx][ny] = v[x][y];
                    q.push({nx, ny});
                }
            } else {
                if(v[nx][ny] > v[x][y]){
                    v[nx][ny] = v[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int k=0;k<s.length();k++){
            m[i][k] = s[k] - '0';
        }
    }
    bfs();
    cout << v[n-1][n-1];
}