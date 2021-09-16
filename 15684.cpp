#include <bits/stdc++.h>
using namespace std;
int n, m, h, l[32][12], ans=987654321;

bool down(){
    for(int i=1;i<=n;i++){
        int row = i;
        for(int j=1;j<=h;j++){
            if(l[j][row] == 1){
                ++row;
            } else if(row >= 1 && l[j][row-1]){
                --row;
            }
        }
        if(i != row){
            return false;
        }
    }
    return true;
}

void setLadder(int x, int y, int cnt){
    if(cnt > 3) {
        ans = min(ans, cnt);
        return;
    }
    for(int i=x;i<=h;i++){
        for(int j=1;j<n;j++){
            if(i == x && j < y) continue;
            if(l[i][j] == 0 && l[i][j-1] == 0 && l[i][j+1] == 0){
                l[i][j] = 1;
                setLadder(i, j+1, cnt+1);
                l[i][j] = 0;
            } 
        }
    }
    bool flag = down();
    if(flag){
        ans = min(ans, cnt);
    }
}

int main(){
    cin >> n >> m >> h;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        l[x][y] = 1;
    }
    setLadder(1, 1, 0);
    if(ans > 3) ans = -1;
    cout << ans;
}