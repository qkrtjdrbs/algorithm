#include <bits/stdc++.h>
using namespace std;

int n, m, Map[50][50], score[4];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};
int dir[] = {3,2,4,1};
vector<pair<int, int>> order;

void setOrder(){
    int x, y, d=0, cnt=1, sum=0;
    x = y = n / 2;
    order.push_back({x, y});
    while(1){
        for(int i=0;i<cnt;i++){
            x += dx[dir[d]];
            y += dy[dir[d]];
            order.push_back({x, y});
            if(!x && !y) return;
        }
        sum++;
        d = d == 3 ? d = 0 : d + 1;
        if(sum == 2){
            cnt++;
            sum = 0;
        }
    }
}

void blizzard(int dir, int dist){
    int x, y;
    x = y = n / 2;
    for(int i=0;i<dist;i++){
        x += dx[dir];
        y += dy[dir];
        Map[x][y] = 0;
    }
}

void explosion(){
    bool flag = 1;
    vector<pair<int, int>> seq;
    while(flag){
        flag = 0;
        for(int i=1;i<order.size();i++){
            int x, y;
            tie(x, y) = order[i];
            if(!Map[x][y]) continue;
            seq.push_back({x, y});
            for(int j=i+1;j<order.size();j++){
                int nx, ny;
                tie(nx, ny) = order[j];
                if(!Map[nx][ny]) continue;
                if(Map[nx][ny] == Map[x][y]) seq.push_back({nx, ny});
                else break;
            }
            if(seq.size() >= 4){
                flag = 1;
                for(auto m : seq){
                    score[Map[m.first][m.second]] += 1;
                    Map[m.first][m.second] = 0;
                }
            }
            i += seq.size()-1;
            seq.clear();
        }
        seq.clear();
    }
}

void makeMarble(){
    int pos = 1, tmp[50][50];
    memset(tmp, 0, sizeof(tmp));
    for(int i=1;i<order.size();i++){
        int x, y, fx, fy, sx, sy, seq=1, j;
        tie(x, y) = order[i];
        if(!Map[x][y]) continue;
        for(j=i+1;j<order.size();j++){
            int nx, ny;
            tie(nx, ny) = order[j];
            if(!Map[nx][ny]) continue;
            if(Map[nx][ny] == Map[x][y]) seq++;
            else break;
        }
        if(pos >= n*n) break;
        tie(fx, fy) = order[pos];
        tie(sx, sy) = order[pos+1];
        tmp[fx][fy] = seq;
        tmp[sx][sy] = Map[x][y];
        pos += 2;
        i = j - 1;
    }
    memcpy(Map, tmp, sizeof(tmp));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    setOrder();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    for(int i=0;i<m;i++){
        int dir, dist;
        cin >> dir >> dist;
        blizzard(dir, dist);
        explosion();
        makeMarble();
    }
    int ans = 0;
    for(int i=1;i<=3;i++) ans += (i * score[i]);
    cout << ans;
}