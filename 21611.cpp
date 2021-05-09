#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, Map[50][50], num[50][50];
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};
vector<pair<int, int>> emp;

void bilzzard(int x, int y, int dir, int dist, int cnt){
    if(dist == -1) return;
    emp.push_back({x, y});
    Map[x][y] = 0;
    bilzzard(x+dx[dir], y+dy[dir], dir, --dist, ++cnt);
}

void numbering(int x, int y, int cnt){
    if(num[x][y] == 0 && x > 0 && x <= n && y > 0 && y <= n){
        num[x][y] = cnt;
        --cnt;
        numbering(x, y+1, cnt);
        numbering(x+1, y, cnt);
        numbering(x, y-1, cnt);
        numbering(x-1, y, cnt);
    }
}

void findEmpty(){
    while(!emp.empty()){
        int x, y;
        tie(x, y) = emp.back();
        emp.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> Map[i][j];
        }
    }
    numbering(1, 1, n*n-1);
    int sx = (n+1)/2;
    int sy = (n+1)/2;
    for(int i=0;i<m;i++){
        int dir, dist;
        cin >> dir >> dist;
        bilzzard(sx, sy, dir, dist, 1);
    }
    cout << "Z";
}