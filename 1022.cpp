#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 5000;
int r1, c1, r2, c2, ans[51][6], idx=1;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool check(int x, int y){
    return r1 <= x && x <= r2 && c1 <= y && y <= c2;
}

void go(int x, int y, int cnt, int len, int dir){    
    if(ans[0][0] && ans[0][c2-c1] && ans[r2-r1][0] && ans[r2-r1][c2-c1]) return;
    int nx, ny;
    for(int i=1;i<=len;i++){
        nx = x + dx[dir]*i;
        ny = y + dy[dir]*i;
        if(nx < 0 || nx > 10000 || ny < 0 || ny > 10000) return;
        if(check(nx, ny)){
            ans[nx-r1][ny-c1] = ++idx;
        } else ++idx;
    }
    dir = dir == 3 ? 0 : dir + 1;
    if(cnt == 1){
        go(nx, ny, 0, len+1, dir);
    } else {
        go(nx, ny, cnt+1, len, dir);
    }
}

int maxNum(){
    int mx = 1;
    for(int i=0;i<=50;i++){
        for(int j=0;j<=5;j++){
            string num = to_string(ans[i][j]);
            mx = max(mx, (int)num.size());
        }
    }
    return mx;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> r1 >> c1 >> r2 >> c2;
    r1 += OFFSET;
    c1 += OFFSET;
    r2 += OFFSET;
    c2 += OFFSET;
    if(check(OFFSET, OFFSET)){
        ans[OFFSET-r1][OFFSET-c1] = idx;
    }
    go(OFFSET, OFFSET, 0, 1, 0);
    int mx = maxNum();
    for(int i=0;i<=r2-r1;i++){
        for(int j=0;j<=c2-c1;j++){
            string num = to_string(ans[i][j]);
            int len = mx - num.size();
            for(int k=0;k<len;k++) cout << ' ';
            cout << num;
            if(j < c2-c1) cout << ' ';
        }
        cout << '\n';
    }
}