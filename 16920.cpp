#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m, p, s[1001], sum[10];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[1001][1001];
bool visited[1001][1001];
vector<pii> castle[10];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> p;
    for(int i=1;i<=p;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(isdigit(Map[i][j])){
                int idx = Map[i][j] - '0';
                castle[idx].push_back({i, j});
                sum[idx]++;
            }
        }
    }
    while(1){
        int cnt = 0;
        for(int i=1;i<=p;i++){
            vector<pii> tmp;
            queue<tuple<int, int, int>> q;
            for(auto cas : castle[i]){
                int x, y;
                tie(x, y) = cas;
                visited[x][y] = 1;
                q.push({x, y, 0});
            }
            while(!q.empty()){
                int x, y, c;
                tie(x, y, c) = q.front();
                q.pop();
                if(s[i] == c) continue;
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(Map[nx][ny] != '.' || visited[nx][ny]) continue;
                    Map[nx][ny] = i + '0';
                    q.push({nx, ny, c+1});
                    tmp.push_back({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
            if(!tmp.size()) cnt++;
            else{
                sum[i] += tmp.size();
                castle[i] = tmp;
            }
        }
        if(cnt == p) break;
    }
    for(int i=1;i<=p;i++) cout << sum[i] << " ";
}