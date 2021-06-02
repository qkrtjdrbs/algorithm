#include <bits/stdc++.h>
using namespace std;
int n, q, res, a[65][65], v[65][65];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void rotate(int startX, int startY, int l){
    int tmp[65][65];
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            tmp[i][j] = a[startX+l-1-j][startY+i];
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            a[startX+i][startY+j] = tmp[i][j];
        }
    }
}

void melt(){
    int tmp[65][65];
    memcpy(tmp, a, sizeof(a));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || !a[nx][ny]) continue;
                if(a[nx][ny]) ++cnt;
            }
            if(cnt < 3 && a[i][j]) {
                --tmp[i][j];
            }
        }
    }
    memcpy(a, tmp, sizeof(a));
}

void dfs(int x, int y){
    v[x][y] = 1;
    res += 1;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || v[nx][ny] || !a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

void ans(){
    int maxIce = 0, sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum += a[i][j];
            if(!v[i][j] && a[i][j]){
                res = 0;
                dfs(i, j);
                maxIce = max(maxIce, res);
            }
        }
    }
    cout << sum << '\n' << maxIce;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    n = pow(2, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    }
    for(int k=0;k<q;k++){
        int l;
        cin >> l;
        l = pow(2, l);
        for(int i=0;i<n;i+=l){
            for(int j=0;j<n;j+=l){
                rotate(i, j, l);
            }
        }
        melt();
    }
    ans();
}
