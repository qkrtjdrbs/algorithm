#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,l,map[1000][1000],visit[1000][1000][11];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void bfs(){
    queue<tuple<int,int,int>> q;
    visit[0][0][0]=1;
    q.push({0,0,0});
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<= nx && nx < n && 0<= ny && ny < m){
                if(map[nx][ny]==0 && visit[nx][ny][z]==0){
                    visit[nx][ny][z]=visit[x][y][z]+1;
                    q.push({nx,ny,z});
                }
                if(z+1<=l && map[nx][ny]==1 && visit[nx][ny][z+1]==0){
                    visit[nx][ny][z+1]=visit[x][y][z]+1;
                    q.push({nx,ny,z+1});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%1d",&map[i][j]);
    }
    bfs();
    bool flag=false;
    int ans=987654321;
    for(int i=0;i<=l;i++){
        if(visit[n-1][m-1][i]==0) continue;
        else{
            flag=true;
            ans=min(ans,visit[n-1][m-1][i]);
        }
    }
    if(!flag) cout << -1;
    else
    {
        cout << ans;
    }
}