#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,map[10][10],dist[10][10],ans=-1;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=map[i][j];
            if(dist[i][j]==2){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(dist[nx][ny]==0){
                    dist[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==0){
                sum+=1;
            }
        }
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int x1=0;x1<n;x1++){
        for(int y1=0;y1<m;y1++){
            if(map[x1][y1]!=0) continue;
            for(int x2=0;x2<n;x2++){
                for(int y2=0;y2<m;y2++){
                    if(map[x2][y2]!=0) continue;
                    for(int x3=0;x3<n;x3++){
                        for(int y3=0;y3<m;y3++){
                            if(map[x3][y3]!=0) continue;
                            if(x1==x2 && y1==y2) continue;
                            if(x2==x3 && y2==y3) continue;
                            if(x1==x3 && y1==y3) continue;                            
                            map[x1][y1]=1;
                            map[x2][y2]=1;
                            map[x3][y3]=1;
                            int tmp=bfs();
                            ans=max(ans, tmp);
                            map[x1][y1]=0;
                            map[x2][y2]=0;
                            map[x3][y3]=0;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}