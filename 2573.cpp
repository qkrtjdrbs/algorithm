#include <bits/stdc++.h>
using namespace std;
int n, m, ice[301][301], Visit[301][301];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int checkZero(int x, int y){
    int res = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(!ice[nx][ny]) ++res;
    }
    return res;
}

void dfs(int x, int y){
    Visit[x][y] = 1;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if(!Visit[nx][ny] && ice[nx][ny]) dfs(nx, ny);
    }
}

void initVisit(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Visit[i][j] = 0;
        }
    }
}

void melt(){
    int year = 0;
    while(1){
        ++year;
        vector<tuple<int, int, int>> list;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ice[i][j]){
                    int cnt = checkZero(i, j);
                    list.push_back({i, j, cnt});
                }
            }
        }
        while(!list.empty()){
            int x, y, cnt;
            tie(x, y, cnt) = list.back();
            list.pop_back();
            ice[x][y] -= cnt;
            if(ice[x][y] < 0) ice[x][y] = 0;
        }
        int test = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!Visit[i][j] && ice[i][j]){
                    ++test;
                    dfs(i, j);
                }
            }
        }
        if(test >= 2){
            cout << year;
            return;
        } else if(test == 0){
            cout << 0;
            return;
        }
        initVisit();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ice[i][j];
        }
    }
    melt();
}