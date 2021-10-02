#include <bits/stdc++.h>
using namespace std;
int t, n, m, dist[104][104][3], visited[104][104];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

char Map[104][104];

void bfs(int i, int j, int k){
    priority_queue<tuple<int, int, int>> pq;
    memset(visited, 0, sizeof(visited));
    dist[i][j][k] = 0;
    visited[i][j] = 1;
    pq.push({0, i, j});
    while(!pq.empty()){
        int cost, x, y;
        tie(cost, x, y) = pq.top();
        pq.pop();
        cost = -cost;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = cost;
            if(nx < 0 || nx >= n+2 || ny < 0 || ny >= m+2) continue;
            if(visited[nx][ny] || Map[nx][ny] == '*') continue;
            if(Map[nx][ny] == '#') nc++;  

            if(dist[nx][ny][k] > nc){
                pq.push({-nc, nx, ny});
                visited[nx][ny] = 1;
                dist[nx][ny][k] = nc;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> n >> m;
        memset(dist, 0xf, sizeof(dist));
        for(int i=0;i<=m+1;i++){
            Map[0][i] = '.';
            Map[n+1][i] = '.';
        }
        for(int i=0;i<=n+1;i++){
            Map[i][0] = '.';
            Map[i][m+1] = '.';
        }
        vector<pair<int, int>> p;
        p.push_back({0, 0});
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> Map[i][j];
                if(Map[i][j] == '$'){
                    p.push_back({i, j});
                }  
            }
        }
        for(int i=0;i<3;i++) {
            bfs(p[i].first, p[i].second, i);
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (Map[i][j] == '*') continue;
				long long tmp = 0;
				for (int k = 0; k < 3; k++) {
					tmp += dist[i][j][k];
				}
				if (Map[i][j] == '#') tmp -= 2;
				ans = min(ans, tmp);
			}
		}

        cout << ans << '\n';
    }
}