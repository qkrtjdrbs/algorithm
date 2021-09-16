#include <bits/stdc++.h>
using namespace std;
int n, home[20][20], ans;
enum State{
    H,
    V,
    D
};

void go(){
    queue<tuple<int, int, int>> q;
    q.push({0, 1, H});
    while(!q.empty()){
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        if(x==n-1 && y==n-1){
            ans += 1;
            continue;
        }
        if(x < 0 || x >= n || y < 0 || y >= n)
            continue;
        if(z == H){
            if(home[x][y+1]<=0){
                q.push({x, y+1, H});
            }
            if(home[x][y+1]<=0 && home[x+1][y+1]<=0 && home[x+1][y]<=0){
                q.push({x+1, y+1, D});
            }
        } else if(z == V){
            if(home[x+1][y]<=0){
                q.push({x+1, y, V});
            }
            if(home[x][y+1]<=0 && home[x+1][y+1]<=0 && home[x+1][y]<=0){
                q.push({x+1, y+1, D});
            }
        } else if(z == D) {
            if(home[x][y+1]<=0){
                q.push({x, y+1, H});
            }
            if(home[x+1][y]<=0){
                q.push({x+1, y, V});
            }
            if(home[x][y+1]<=0 && home[x+1][y+1]<=0 && home[x+1][y]<=0){
                q.push({x+1, y+1, D});
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> home[i][j];
    }
    go();
    cout << ans;
}
