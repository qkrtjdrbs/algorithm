#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int n,m,miro[101][101],visit[101][101];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(){
    deque<pair<int, int>> dq;
    dq.push_back({1,1});
    visit[1][1]=0;
    while(!dq.empty()){
        int x=dq.front().first;
        int y=dq.front().second;
        dq.pop_front();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(1<=nx && nx <= n && 1<=ny && ny<=m){
                if(visit[nx][ny]==-1 && miro[nx][ny]==0){
                    visit[nx][ny]=visit[x][y];
                    dq.push_front({nx,ny});
                }
                if(visit[nx][ny]==-1 && miro[nx][ny]==1){
                    visit[nx][ny]=visit[x][y]+1;
                    dq.push_back({nx,ny});
                }
            }
        }
    }
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&miro[i][j]);
            visit[i][j]=-1;
        }
    }
    bfs();
    cout << visit[n][m];
}