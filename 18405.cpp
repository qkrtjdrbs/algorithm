#include <bits/stdc++.h>
using namespace std;

int n, k, Map[201][201];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void go(int sec, int xx, int yy){
    priority_queue<tuple<int, int, int>> pq;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Map[i][j]){
                pq.push({-Map[i][j], i, j});
            }
        }
    }
    for(int i=0;i<sec;i++){
        int m = pq.size();
        priority_queue<tuple<int, int, int>> tmp;
        for(int j=0;j<m;j++){
            auto [num, x, y] = pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx <= 0 || nx > n || ny <= 0 || ny > n || Map[nx][ny]) continue;
                tmp.push({num, nx, ny});
                Map[nx][ny] = -num;
            }
        }
        pq = tmp;
    }
    cout << Map[xx][yy];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Map[i][j];
        }
    }
    int sec, x, y;
    cin >> sec >> x >> y;
    go(sec, x, y);
}