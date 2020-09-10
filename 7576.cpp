#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,tomato[1000][1000],visit[1000][1000],ans=0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int x, int y){
    scanf("%d %d",&m,&n);
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tomato[i][j]);
            visit[i][j]=-1;
            if(tomato[i][j]==1){
                q.push({i,j});
                visit[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int go_x=x+dx[k];
            int go_y=y+dy[k];
            if(go_x >= 0 && go_x < n && go_y >= 0 && go_y <m){
                if(tomato[go_x][go_y]==0 && visit[go_x][go_y]==-1){
                    q.push({go_x, go_y});
                    visit[go_x][go_y]=visit[x][y]+1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tomato[i][j]==0 && visit[i][j]==-1){
                printf("-1");
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,visit[i][j]);
        }
    }
    printf("%d",ans);
}
int main(){
    bfs(0,0);
}