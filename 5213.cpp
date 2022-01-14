#include <bits/stdc++.h>
using namespace std;

int n, parent[250000];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[501][1010];

typedef struct tile {
    int val, num;
}Tile;

Tile Map[501][1001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    int num = 1;
    for(int i=0;i<n;i++){
        for(int j=(i % 2 ? 1 : 0);j<(i % 2 ? n*2-1 : n*2);j+=2){
            int a, b;
            cin >> a >> b;
            Map[i][j].val = a;
            Map[i][j].num = num;
            Map[i][j+1].val = b;
            Map[i][j+1].num = num;
            num++;
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});
    visited[0][0] = 1;
    visited[0][1] = 1;
    parent[1] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n*2 || ny < 0 || ny >= n*2) continue;
            if(visited[nx][ny] || !Map[nx][ny].val) continue;
            if(Map[x][y].num != Map[nx][ny].num){
                if(Map[x][y].val == Map[nx][ny].val){
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    parent[Map[nx][ny].num] = Map[x][y].num;

                    if(ny - 1 >= 0 && Map[nx][ny-1].num == Map[nx][ny].num){
                        q.push({nx, ny-1});
                        visited[nx][ny-1] = 1;
                    } else if(ny + 1 >= 0 && Map[nx][ny+1].num == Map[nx][ny].num){
                        q.push({nx, ny+1});
                        visited[nx][ny+1] = 1;
                    }
                }
            }
        }
    }
    stack<int> st;
    for(int k=num;k>=1;k--){
        if(parent[k]){
            for(int i=k;i!=1;i=parent[i]){
                st.push(i);
            }
            break;
        }
    }
    st.push(1);
    cout << st.size() << '\n';
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}