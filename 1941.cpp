#include <bits/stdc++.h>
using namespace std;

string Map[5];
vector<pair<int, int>> v;
int Visit[26], ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool check() {
    int adj[5][5];
    memset(adj, false, sizeof(adj));
    int x = v[0].first;
    int y = v[0].second;
    queue<pair<int, int>> q;
    adj[x][y] = 1;
    q.push({x, y});
    while(!q.empty()){
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();
        for(auto j : v){
            for(int k=0;k<4;k++){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || adj[nx][ny]) continue;
                if(nx == j.first && ny == j.second) {
                    adj[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for(auto k : v){
        if(!adj[k.first][k.second]) return false;
    }
    return true;
}

void dfs(int idx, int S, int Y){
    if(S + Y == 7){
        if(S < Y) return;
        if(check()) ans++;
        return;
    }
    for(int i=idx;i<25;i++){
        int x = i / 5;
        int y = i % 5;
        if(!Visit[i]){
            Visit[i] = 1;
            v.push_back({x, y});
            if(Map[x][y] == 'S') dfs(i+1, S+1, Y);
            else dfs(i+1, S, Y+1);
            v.pop_back();
            Visit[i] = 0;
        }
    }
}

int main(){
    int color = 1;
    for(int i=0;i<5;i++)
        cin >> Map[i];
    dfs(0, 0, 0);
    cout << ans;
}