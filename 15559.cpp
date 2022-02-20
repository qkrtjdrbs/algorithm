#include <bits/stdc++.h>
using namespace std;

int n, m, ans, parent[1000001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[1001][1001];
char Map[1001][1001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

void go(int x, int y){
    visited[x][y] = 1;
    int dir;
    if(Map[x][y] == 'W') dir = 0;
    else if(Map[x][y] == 'E') dir = 1;
    else if(Map[x][y] == 'N') dir = 2;
    else dir = 3;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    Union(x*m+y, nx*m+ny);
    if(!visited[nx][ny]) go(nx, ny);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    for(int i=0;i<n*m;i++) parent[i] = i;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                go(i, j);
            }
        }
    }
    set<int> st;
    for(int i=0;i<n*m;i++){
        st.insert(Find(i));
    }
    cout << st.size();
}