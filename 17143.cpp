#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};
vector<pair<int, pair<int, int>>> Map[102][102];

struct info{
    int x, y, s, d, z;
};

void getShark(int y){
    for(int i=1;i<=n;i++){
        if(Map[i][y].empty()) continue;
        int s, d, z;
        z = Map[i][y][0].first;
        s = Map[i][y][0].second.first;
        d = Map[i][y][0].second.second;
        ans += z;
        Map[i][y].clear();
        break;
    }
}

void moveShark(int x, int y, int d, int s, int z){
    int cnt = s;
    int nx = x, ny = y;
    while(cnt--){
        nx = x + dx[d];
        ny = y + dy[d];
        if(nx < 1 || nx > n || ny < 1 || ny > m){
            if(d == 1 || d == 3){
                d = d + 1;
            } else {
                d = d - 1;
            }    
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }
    if(Map[nx][ny].size() == 0)
        Map[nx][ny].push_back({z, {s, d}});
    else {
        if(Map[nx][ny][0].first < z)
            Map[nx][ny].push_back({z, {s, d}});
    }
}

void fishingman(){
    for(int pos=1;pos<=m;pos++){
        getShark(pos);
        queue<info> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(Map[i][j].empty()) continue;
                int s, d, z, ni, nj;
                z = Map[i][j][0].first;
                s = Map[i][j][0].second.first;
                d = Map[i][j][0].second.second;     
                q.push({i, j, s, d, z});
                Map[i][j].clear();            
            }
        }
        while(!q.empty()){
            int x, y, s, d, z;
            x = q.front().x;
            y = q.front().y;
            s = q.front().s;
            d = q.front().d;
            z = q.front().z;
            q.pop();
            moveShark(x, y, d, s, z);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        Map[r][c].push_back({z, {s, d}});
    }
    fishingman();
    cout << ans;
}