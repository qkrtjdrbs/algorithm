#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
int n,visit[101][101][2];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char map[101][101];
void bfs(int startx, int starty, int blind, int group){
    queue<pair<int,int>> q;
    q.push({startx,starty});
    visit[startx][starty][blind]=group;
    while(!q.empty()){
        int x,y;
        tie(x, y)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<n && 0<=ny && ny<n){
                if(blind==0){
                    if(visit[nx][ny][blind]==0 && map[nx][ny]==map[x][y]){
                        visit[nx][ny][blind]=group;
                        q.push({nx,ny});
                    }
                }
                else{
                    if(visit[nx][ny][blind]==0 && map[nx][ny]==map[x][y]){
                        visit[nx][ny][blind]=group;
                        q.push({nx,ny});
                    }
                    if(visit[nx][ny][blind]==0 && map[x][y]=='G' && map[nx][ny]=='R'){
                        visit[nx][ny][blind]=group;
                        q.push({nx,ny});
                    }
                    if(visit[nx][ny][blind]==0 && map[x][y]=='R' && map[nx][ny]=='G'){
                        visit[nx][ny][blind]=group;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
    }
    int g=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j][0]==0){
                bfs(i,j,0,g);
                g+=1;
            }
        }
    }
    g=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j][1]==0){
                bfs(i,j,1,g);
                g+=1;
            }
        }
    }
    int ans1=1,ans2=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans1=max(ans1,visit[i][j][0]);
            ans2=max(ans2,visit[i][j][1]);
        }
    }
    cout << ans1 << ' ' << ans2;
}
