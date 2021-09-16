#include <bits/stdc++.h>
using namespace std;
int n, m, ans=987654321, Map[51][51], v[51][51], selected[11];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<pair<int, int>> virus;

int bfs(){
    queue<pair<int, int>> q;
    int len = virus.size();
    for(int i=0;i<len;i++){
        if(selected[i]){
            int x, y;
            tie(x, y) = virus[i];
            v[x][y] = 1;
            q.push({x, y});
        }
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!Map[nx][ny] || Map[nx][ny] == 2){
               if(!v[nx][ny]) {
                   v[nx][ny] = v[x][y] + 1;
                   q.push({nx, ny});
               } else {
                   if(v[nx][ny] > v[x][y] + 1){
                       v[nx][ny] = v[x][y] + 1;
                       q.push({nx, ny});
                   }
               }
            }
        }
    }
    int minTime = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!Map[i][j]){
                if(!v[i][j]){
                    minTime = 987654321;
                }
                minTime = max(minTime, v[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v[i][j] = 0;
        }
    }
    return minTime;
}

void drop(int cur, int cnt){
    if(cnt == m){
        ans = min(ans, bfs());
        return;
    }
    int len = virus.size();
    for(int next=cur;next<len;next++){
        if(selected[next]) continue;
        selected[next] = 1;
        drop(next, cnt+1);
        selected[next] = 0;
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 2){
                virus.push_back({i, j});
            }
        }
    }
    drop(0, 0);  
    if(ans == 987654321) ans = -1;
    if(ans == -1) cout << ans;
    else cout << ans-1;
}