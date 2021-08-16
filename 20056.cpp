#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

typedef struct fireBall {
    int x, y, m, d, s;    
}Fb;

vector<Fb> fb;

vector<Fb> Map[51][51];

void go(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            Map[i][j].clear();
    for(auto cur : fb){
        int nx = (cur.x + dx[cur.d] * cur.s) % n;
        int ny = (cur.y + dy[cur.d] * cur.s) % n;
        if(nx <= 0) nx += n;
        if(ny <= 0) ny += n;
        Map[nx][ny].push_back({nx, ny, cur.m, cur.d, cur.s});
        cur.x = nx;
        cur.y = ny;
    }
    vector<Fb> tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(Map[i][j].size() == 1){
                vector<Fb> v = Map[i][j];
                tmp.push_back({i, j, v[0].m, v[0].d, v[0].s});
            } else if(Map[i][j].size() >= 2){
                int mSum = 0, sSum = 0, fbSize = Map[i][j].size();
                bool even = true, odd = true;
                for(auto k : Map[i][j]){
                    if(k.d % 2 == 0) odd = false;
                    else even = false;
                    mSum += k.m;
                    sSum += k.s;
                }
                int dvM = mSum / 5;
                int dvS = sSum / fbSize;
                int dir;
                if(!dvM) continue;
                if(even || odd) dir = 0;  
                else dir = 1;    
                for(int k=0;k<4;k++){
                    tmp.push_back({i, j, dvM, dir, dvS});
                    dir += 2;
                }
            }
        }
    }
    fb = tmp;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        fb.push_back({x, y, m, d, s});
        Map[x][y].push_back({x, y, m, d, s});
    }
    for(int i=0;i<k;i++){
        go();
    }
    int ans = 0;
    for(auto i : fb) ans += i.m;
    cout << ans << '\n';
}