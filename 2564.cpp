#include <bits/stdc++.h>
using namespace std;

int n, m, k, sx, sy, Map[102][102], visited[102][102];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int, int>> v;

int go(int ex, int ey){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    int ans = 987654321;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(x == ex && y == ey){
            ans = min(ans, visited[x][y]-1);
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if(nx != 0 && nx != n && ny != 0 && ny != m) continue;
            if(visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y]+1;
        }
    }
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> m >> n >> k;
    for(int i=0;i<=k;i++){
        int d, idx;
        cin >> d >> idx;
        if(d == 1){
            v.push_back({0, idx});
        } else if(d == 2){
            v.push_back({n, idx});
        } else if(d == 3){
            v.push_back({idx, 0});
        } else {
            v.push_back({idx, m});
        }
    }
    int sum = 0;
    sx=v[k].first, sy=v[k].second;
    for(int i=0;i<k;i++){
        auto [x, y] = v[i];
        sum += go(x, y);
    }
    cout << sum;
}