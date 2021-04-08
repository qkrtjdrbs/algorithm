#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int w,h,sx1=-1,sy1,sx2,sy2,visit[101][101];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
char map[101][101];
void bfs(int startx, int starty){
    memset(visit, -1, sizeof(visit));
    queue<pair<int,int>> q;
    q.push({startx, starty});
    visit[startx][starty]=0;
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            while(0<=nx && nx<h && 0<=ny && ny<w){
                if(map[nx][ny]=='*') break;
                if(visit[nx][ny]==-1){
                    q.push({nx,ny});
                    visit[nx][ny]=visit[x][y]+1;
                }
                nx+=dx[k];
                ny+=dy[k];
            }
        }
    }
}
int main(){
    cin >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
            if(map[i][j]=='C'){
                if(sx1==-1){
                    sx1=i;
                    sy1=j;
                }
                else
                {
                    sx2=i;
                    sy2=j;
                }         
            }
        }       
    }
    bfs(sx1, sy1);
    cout << visit[sx2][sy2]-1;
}