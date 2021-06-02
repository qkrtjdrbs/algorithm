#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, Map[50][50], tmp[50][50];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};
int tdx[] = {0,1,0,-1};
int tdy[] = {-1,0,1,0};
int explode[4];

bool flag;
vector<pair<int, int>> emp;
vector<pair<int, int>> e;
vector<pair<int, int>> mul;

void bilzzard(int x, int y, int dir, int dist, int cnt){
    if(dist == -1) return;
    emp.push_back({x, y});
    Map[x][y] = 0;
    bilzzard(x+dx[dir], y+dy[dir], dir, --dist, ++cnt);
}

void tornado(int x, int y, int cnt, int maxCnt, int dirChange, int dir){
    if(x == 0 && y == -1) return;
    int nx, ny, nd;
    if(cnt == maxCnt){
        dir == 3 ? nd = 0 : nd = dir + 1;
        nx = x + tdx[nd];
        ny = y + tdy[nd];
        if(Map[nx][ny])   
            mul.push_back({nx, ny}); 
        if(dirChange == 1){
            tornado(nx, ny, 1, maxCnt+1, 0, nd);
        } else {
            tornado(nx, ny, 1, maxCnt, dirChange+1, nd);
        }
    } else {    
        nx = x + tdx[dir];
        ny = y + tdy[dir];
        if(Map[nx][ny])  
            mul.push_back({nx, ny});
        tornado(nx, ny, cnt+1, maxCnt, dirChange, dir);
    }
}

void grouping(int x, int y, int cnt, int maxCnt, int dirChange, int dir){
    if(x == 0 && y == -1) return;
    int nx, ny, nd;
    if(cnt == maxCnt){
        dir == 3 ? nd = 0 : nd = dir + 1;
        nx = x + tdx[nd];
        ny = y + tdy[nd];
        if(Map[nx][ny])   
            mul.push_back({nx, ny}); 
        if(dirChange == 1){
            grouping(nx, ny, 1, maxCnt+1, 0, nd);
        } else {
            grouping(nx, ny, 1, maxCnt, dirChange+1, nd);
        }
    } else {    
        nx = x + tdx[dir];
        ny = y + tdy[dir];
        if(Map[nx][ny])  
            mul.push_back({nx, ny});
        grouping(nx, ny, cnt+1, maxCnt, dirChange, dir);
    }
}

void findEmpty(){
    while(!emp.empty()){
        int x, y;
        tie(x, y) = emp.back();
        emp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Map[i][j];
        }
    }
    int sx = (n+1)/2;
    int sy = (n+1)/2;
    for(int i=0;i<m;i++){
        int dir, dist;
        cin >> dir >> dist;
        bilzzard(sx, sy, dir, dist, 1);
        while(1){
            flag = false;
            tornado(sx, sy, 0, 1, 0, 0);
            int seq = 1;
            for(int i=1;i<e.size();i++){
                int x = e[i].first;
                int y = e[i].second;
                int px = e[i-1].first;
                int py = e[i-1].second;
                if(Map[x][y] == 0) {
                    continue;
                }
                if(Map[x][y] != Map[px][py]){
                    if(seq >= 4){
                        for(int j=i-seq;j<i;j++){
                            int x, y;
                            tie(x, y) = e[j];
                            explode[Map[x][y]]++;
                            Map[x][y] = 0;
                        }
                    }
                    seq = 1;
                } else {
                    seq++;
                    if(seq == 4){
                        flag = true;
                    }
                }
            }
            e.clear(); 
            if(!flag) break;
        }
    }
    int ans = 0;
    for(int i=1;i<=3;i++){
        ans += i * explode[i];
    }
    cout << ans;
}