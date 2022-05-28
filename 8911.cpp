#include <bits/stdc++.h>
using namespace std;

int t;
int dx[4][2] = {{1,-1},{0,0},{-1,1},{0,0}};
int dy[4][2] = {{0,0},{-1,1},{0,0},{1,-1}};

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        string cmds;
        int dir=0, x=0, y=0, mnx=0, mny=0, mxx=0, mxy=0;
        cin >> cmds;
        for(auto cmd : cmds){
            int nx=x, ny=y;
            if(cmd == 'F'){
                nx += dx[dir][0];
                ny += dy[dir][0];
            } else if(cmd == 'B'){
                nx += dx[dir][1];
                ny += dy[dir][1];
            } else if(cmd == 'L'){
                dir = dir == 3 ? 0 : dir+1;
            } else if(cmd == 'R'){
                dir = dir == 0 ? 3 : dir-1;
            }
            mnx = min(mnx, nx); mny = min(mny, ny);
            mxx = max(mxx, nx); mxy = max(mxy, ny);
            x = nx; y = ny;
        }
        cout << (mxx-mnx)*(mxy-mny) << '\n';
    }
}