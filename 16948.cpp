#include <iostream>
#include <queue>
using namespace std;
int n,r1,c1,r2,c2,dist[201][201];
int dx[]={-2,-2,0,0,2,2};
int dy[]={-1,1,-2,2,-1,1};
void bfs(){
    queue<pair<int, int>> q;
    q.push({r1,c1});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<6;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(dist[nx][ny]==0){
                    q.push({nx,ny});
                    dist[nx][ny]=dist[x][y]+1;
                    if(nx==r2 && ny==c2){
                        cout << dist[nx][ny];
                        return;
                    }
                }
            }
        }
    }
    cout << -1;
}
int main(){
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    bfs();
}