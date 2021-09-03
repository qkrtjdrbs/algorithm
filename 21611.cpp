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
    int prev = 0;
    vector<pair<int, int>> seq;
    while(flag){
        prev = 0; flag = 0;
        for(int i=1;i<order.size();i++){
            int x, y;
            tie(x, y) = order[i];
            if(!Map[x][y]) continue;
            if(!prev) {
                seq.push_back({x, y});
                prev = Map[x][y];
                continue;
            }
            if(prev == Map[x][y]) seq.push_back({x, y});
            else {
                int len = seq.size();
                if(len >= 4){
                    for(auto j : seq) Map[j.first][j.second] = 0;
                    score[prev] += len;
                    flag = 1;
                }
                seq.clear();
                seq.push_back({x, y});
                prev = Map[x][y];
            }
        }
        if(seq.size() >= 4){
            for(auto x : seq) Map[x.first][x.second] = 0;
            score[prev] += seq.size();
        }
        seq.clear();
    }
}

void makeMarble(){
    int seq = 1, prev = 0, pos = 1, tmp[50][50];
    memset(tmp, 0, sizeof(tmp));
    for(int i=1;i<order.size();i++){
        int x, y;
        tie(x, y) = order[i];
        if(!Map[x][y]) continue;
        if(!prev) {
            prev = Map[x][y];
            continue;
        }
        if(prev == Map[x][y]) seq++;
        else {
            int fx, fy, sx, sy;
            tie(fx, fy) = order[pos];
            tie(sx, sy) = order[pos+1];
            tmp[fx][fy] = seq;
            tmp[sx][sy] = prev;
            seq = 1;
            pos += 2;
            if(pos >= n*n) break;
            prev = Map[x][y];
        }
    }
    if(pos < n*n){
        int fx, fy, sx, sy;
        tie(fx, fy) = order[pos];
        tie(sx, sy) = order[pos+1];
        tmp[fx][fy] = seq;
        tmp[sx][sy] = prev;
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