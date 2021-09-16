#include <bits/stdc++.h>
using namespace std;
int m, n, k, paper[101][101], area;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x, int y){
    paper[x][y] = 1;
    ++area;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(!paper[nx][ny]){
            dfs(nx, ny);
        }
    }
}

void fillPaper(int x1, int y1, int x2, int y2){
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            paper[i][j] = 1;
        }
    }
}

int main(){
    vector<int> ans;
    cin >> m >> n >> k;
    for(int i=0;i<k;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        fillPaper(x1, y1, x2, y2);
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!paper[i][j]){
                ++cnt;
                dfs(i, j);
                ans.push_back(area);
                area = 0;
            }
        }
    }
    sort(ans.begin(), ans.end());
    int len = ans.size();
    cout << cnt << '\n';
    for(int i=0;i<len;i++){
        cout << ans[i] << " ";
    }
}   