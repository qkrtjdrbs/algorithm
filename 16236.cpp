#include <iostream>
#include <set>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int map[21][21],n,sx,sy,eat=0,size=2,ans=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool lv=false;
tuple<int, int, int> bfs(int startx, int starty, int size){
    int visit[21][21];
    queue<pair<int,int>> q;
    vector<tuple<int,int,int>> route;
    memset(visit,-1,sizeof(visit));
    q.push({startx,starty});
    visit[startx][starty]=0;
    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front(); q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<n && 0<=ny && ny<n && visit[nx][ny]==-1){
                if(map[nx][ny]==0){
                    visit[nx][ny]=visit[x][y]+1;
                    q.push({nx,ny});
                    continue;
                }
                if(map[nx][ny]==size){
                    visit[nx][ny]=visit[x][y]+1;
                    q.push({nx,ny});
                }
                if(map[nx][ny]<size){
                    visit[nx][ny]=visit[x][y]+1;
                    route.push_back({visit[nx][ny],nx,ny});
                }
            }
        }
    }
    if(route.empty()){
        return {-1,-1,-1};
    }
    sort(route.begin(), route.end());
    return route[0];
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                sx=i;
                sy=j;
                map[i][j]=0;
            }
        }
    }
    int dist=0,x,y;
    while(1){
        tie(dist, x, y)=bfs(sx,sy,size);
        if(dist==-1) break;
        ans+=dist;
        map[x][y]=0;
        eat+=1;
        if(eat==size){
            eat=0;
            size+=1;
        }
        sx=x;
        sy=y;
    }
    cout << ans;
}
