#include <bits/stdc++.h>
using namespace std;
int n, m, d, ans, res, Map[17][17], k[17][17], tmp[17][17], v[17][17], a[17];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
priority_queue<tuple<int, int, int>> pq[3];

bool isEnd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]) return false;
        }
    }
    return true;
}

void enemyDown(){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 1){
                if(i == n-1){
                    Map[i][j] = 0;
                } else {
                    swap(Map[i][j], Map[i+1][j]);
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        Map[0][i] = 0;
    }
}

void killEnemy(){
    for(int i=0;i<3;i++){
        if(!pq[i].empty()){
            int dist, x, y;
            tie(dist, y, x) = pq[i].top();
            pq[i].pop();
            Map[-x][-y] = 0;
            k[-x][-y]++;
            if(k[-x][-y] == 1)
                res++;
        }
        priority_queue<tuple<int, int, int>> del;
        pq[i].swap(del);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            k[i][j] = 0;
        }
    }
}

void detect(int archer, int pqIdx){
    queue<pair<int, int>> q;
    q.push({n, archer});
    v[n][archer] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(v[x][y] > d + 1) continue;
        if(v[x][y] <= d + 1 && Map[x][y] == 1){
            pq[pqIdx].push({-v[x][y], -y, -x});
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny]) continue;
            v[nx][ny] = v[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j] = 0;
        }
    }
}

void arrange(int idx, int cnt){
    if(cnt == 3){
        memcpy(Map, tmp, sizeof(Map));
        while(1){
            int c = 0;
            for(int i=0;i<m;i++){
                if(a[i]){
                    detect(i, c);
                    c++;
                }
            }
            killEnemy();
            enemyDown();
            if(isEnd()) {
                ans = max(ans, res);
                res = 0;
                return;
            }
        }
    }
    for(int i=idx;i<m;i++){
        if(!a[i]){
            a[i] = 1;
            arrange(i+1, cnt+1);
            a[i] = 0;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            tmp[i][j] = Map[i][j];
    }
    arrange(0, 0);
    cout << ans;
}