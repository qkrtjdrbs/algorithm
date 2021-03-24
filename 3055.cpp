#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;
int r,c,visit[51][51],flood[51][51],Dx,Dy,Sx,Sy,Fx[50],Fy[50],cnt=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char map[51][51];
void flood_bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<cnt;i++){
        q.push({Fx[i],Fy[i]});
        flood[Fx[i]][Fy[i]]=0;
    }
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<r && 0<=ny && ny<c){
                if(map[nx][ny]!='S' && map[nx][ny]!='X' && map[nx][ny]!='D' && flood[nx][ny]==-1){
                    flood[nx][ny]=flood[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
}
void bfs(){
    queue<pair<int,int>> q;
    q.push({Sx,Sy});
    visit[Sx][Sy]=0;
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<r && 0<=ny && ny<c){
                if (visit[nx][ny] != -1) continue;
                if (map[nx][ny] == 'X') continue;
                if (flood[nx][ny] != -1 && visit[x][y]+1 >= flood[nx][ny]) continue;
                visit[nx][ny]=visit[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j]=='D'){
                Dx=i;
                Dy=j;
            }
            if(map[i][j]=='S'){
                Sx=i;
                Sy=j;
            }
            if(map[i][j]=='*'){
                Fx[cnt]=i;
                Fy[cnt]=j;
                cnt+=1;
            }
        }
    }
    memset(flood,-1,sizeof(flood));
    memset(visit,-1,sizeof(visit));
    flood_bfs();
    bfs();
    if(visit[Dx][Dy]==-1)
        cout << "KAKTUS";
    else
        cout << visit[Dx][Dy];
}