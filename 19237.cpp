#include <bits/stdc++.h>
using namespace std;

typedef struct Shark {
    int x, y;
}Shark;

Shark shark[401];
int n, m, k;
int dx[] ={0,-1,1,0,0};
int dy[] ={0,0,0,-1,1};
int sD[401];

vector<int> prior[401][5];
pair<int, int> Map[21][21];

void sharkMove(){
    vector<pair<int, int>> tmp[21][21];
    for(int i=1;i<=m;i++){
        Map[shark[i].x][shark[i].y].second = k;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Map[i][j].first == 0) continue;
            tmp[i][j].push_back({Map[i][j].first, Map[i][j].second});
        }
    }
    for(int i=1;i<=m;i++){
        if(shark[i].x == -1) continue;
        int cx = shark[i].x;
        int cy = shark[i].y;
        int cd = sD[i];
        bool isEmpty = false;
        for(auto dir : prior[i][cd]){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(0 >= nx || nx > n || 0 >= ny || ny > n) continue;
            if(Map[nx][ny].first == 0){
                isEmpty = true;
                tmp[nx][ny].push_back({i, k});
                shark[i].x = nx;
                shark[i].y = ny;
                sD[i] = dir;
                break;
            }
        }
        if(!isEmpty){
            for(auto dir : prior[i][cd]){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if(0 >= nx || nx > n || 0 >= ny || ny > n) continue;
                if(tmp[nx][ny][0].first == Map[cx][cy].first){
                    isEmpty = true;
                    tmp[nx][ny].pop_back();
                    tmp[nx][ny].push_back({i, k});
                    shark[i].x = nx;
                    shark[i].y = ny;
                    sD[i] = dir;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tmp[i][j].size() > 1){
                sort(tmp[i][j].begin(), tmp[i][j].end());
                for(int x=1;x<tmp[i][j].size();x++){
                    int num = tmp[i][j][x].first;
                    shark[num] = {-1, -1};
                }
                tmp[i][j].erase(tmp[i][j].begin()+1, tmp[i][j].end());
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tmp[i][j].size() == 0){
                Map[i][j] = {0, k};
            } else
                Map[i][j] = tmp[i][j][0];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Map[i][j].second -= 1;
            if(Map[i][j].second == 0){
                Map[i][j].first = 0;
            }
        }
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num;
            cin >> num;
            Map[i][j] = {num, k};
            if(num)
                shark[num] = {i, j};
        }
    }
    for(int i=1;i<=m;i++){
        int dir;
        cin >> dir;
        sD[i] = dir;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=4;j++){
            for(int k=1;k<=4;k++){
                int p;
                cin >> p;
                prior[i][j].push_back(p);
            }
        }
    }
    int sec = 1;
    while(sec <= 1000){
        sharkMove();
        int end = 0;
        for(int i=1;i<=m;i++)
            if(shark[i].x == -1 && i != 1) end++;
        if(end == m-1) break;
        sec++;
    }
    sec > 1000 ? cout << -1 : cout << sec;
}