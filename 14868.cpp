#include <bits/stdc++.h>
using namespace std;

int n, k, ans=0, visited[2001][2001], parent[100001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
    
queue<tuple<int, int, int>> q;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

int Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

void process2(int x, int y, int year){
    for(int j=0;j<4;j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if(!visited[nx][ny]) continue;
        if(Union(visited[x][y], visited[nx][ny])){
            ans = max(ans, year);
        }
    }
}

void process(int x, int y, int z, int year){
    for(int j=0;j<4;j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if(visited[x][y] == visited[nx][ny]) continue;
        if(!visited[nx][ny]){
            q.push({nx, ny, z});
            visited[nx][ny] = z;
            process2(nx, ny, year);
        } else {
            if(Union(visited[x][y], visited[nx][ny])){
                ans = max(ans, year);
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=k;i++) parent[i] = i;
    for(int i=1;i<=k;i++){
        int x, y;
        cin >> x >> y;
        q.push({x, y, i});
        visited[x][y] = i;
        process2(x, y, 0);
    }
    for(int year=1;;year++){
        int len = q.size();
        if(len == 0) break;
        while(len--){
            auto [x, y, z] = q.front();
            q.pop();
            process(x, y, z, year);
        }
    }
    cout << ans;
}