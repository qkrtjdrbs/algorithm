#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, cnt, height[51][51];
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
bool visited[51][51];
char Map[51][51];
vector<int> heights;

bool bfs(int l, int r){
    queue<pair<int, int>> q;
    if(heights[l] <= height[sx][sy] && height[sx][sy] <= heights[r]){
        q.push({sx, sy});
    } else return false;
    visited[sx][sy] = 1;

    int delCnt = 0;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(Map[x][y] == 'K'){
            if(++delCnt == cnt) return true;
        }
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            if(heights[l] <= height[nx][ny] && height[nx][ny] <= heights[r]){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'P'){
                sx = i; sy = j;
            } else if(Map[i][j] == 'K') cnt++;
        }
    }
    set<int> tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> height[i][j];
            tmp.insert(height[i][j]);
        }
    }
    for(auto x : tmp) heights.push_back(x);

    int ans = 987654321;
    int l = 0, r = 0;
    while(r < heights.size()){
        while(l <= r){
            memset(visited, 0, sizeof(visited));
            if(bfs(l, r)){
                ans = min(ans, heights[r] - heights[l]);
                l++;
            } else break;
        }
        r++;
    }
    cout << ans;
}