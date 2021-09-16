#include <bits/stdc++.h>
using namespace std;
int n, k, Map[13][13];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

vector<int> Visit[13][13];
tuple<int, int, int> h[11];

enum Color
{
    WHITE = 0,
    RED = 1,
    BLUE = 2,
};

int move(int idx){
    int cx, cy, cd;
    tie(cx, cy, cd) = h[idx];
    int nx = cx + dx[cd];
    int ny = cy + dy[cd];
    vector<int> &cur = Visit[cx][cy];
    
    auto it = find(cur.begin(), cur.end(), idx);
    
    if(Map[nx][ny] == BLUE || nx <= 0 || nx > n || ny <= 0 || ny > n){       
        vector<int> &next = Visit[nx][ny];
        if(cd == 1 || cd == 3){
            cd += 1;
        } else {
            cd -= 1;
        }
        nx = cx + dx[cd];
        ny = cy + dy[cd];
        if(Map[nx][ny] == BLUE || nx <= 0 || nx > n || ny <= 0 || ny > n){
            h[idx] = {cx, cy, cd};
            return 0;
        }
        h[idx] = {nx, ny, cd};
    } if(Map[nx][ny] == WHITE){
        vector<int> &next = Visit[nx][ny];
        for(auto x = it; x < cur.end(); x++){
            next.push_back(*x);
            int tmp, d;
            tie(tmp, tmp, d) = h[*x];
            h[*x] = {nx, ny, d};
        }
        cur.erase(it, cur.end());
        return next.size();
    } if(Map[nx][ny] == RED){
        vector<int> &next = Visit[nx][ny];
        for(auto x = it; x < cur.end(); x++){
            next.push_back(*x);
            int tmp, d;
            tie(tmp, tmp, d) = h[*x];
            h[*x] = {nx, ny, d};
        }
        cur.erase(it, cur.end());
        it = find(next.begin(), next.end(), idx);
        reverse(it, next.end());
        return next.size();
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin >> Map[i][j];
    }
    for(int i=1;i<=k;i++){
        int a, b, d;
        cin >> a >> b >> d;
        Visit[a][b].push_back(i);
        h[i] = {a, b, d};
    }
    int turn = 1;
    while(turn <= 1000){
        for(int i=1;i<=k;i++){
            int cnt = move(i);
            if(cnt >= 4) {
                cout << turn;
                return 0;
            }
        }
        turn++;
    }
    cout << -1;
}