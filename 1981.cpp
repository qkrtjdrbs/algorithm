#include <bits/stdc++.h>
using namespace std;

int n, m, ans=987654321, Map[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<int> v;

bool bfs(int l, int r){
    if(Map[0][0] < v[l] || Map[0][0] > v[r]) return false;
    bool visited[101][101];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(x == n-1 && y == n-1) return true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || Map[nx][ny] < v[l] || Map[nx][ny] > v[r]) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
            s.insert(Map[i][j]);
        }
    }
    for(auto x : s) v.push_back(x);
    m = v.size();
    int l = 0, r = 0;
    while(l <= r && r < m){
        if(bfs(l, r)) {
            ans = min(ans, v[r]-v[l]);
            l++;
        } else r++;
    }
    cout << ans;
}