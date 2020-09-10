#include <iostream>
#include <algorithm>
using namespace std;
int n,m,p[501][501],ans;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool visit[501][501];
void go(int x, int y, int sum, int cnt){
    if(cnt==4){
        ans=max(ans, sum);
        return;
    }
    visit[x][y]=true;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(0<=nx && nx<n && 0<=ny && ny<m){
            if(!visit[nx][ny]){
                go(nx,ny,sum+p[nx][ny],cnt+1);
                visit[nx][ny]=false;
            }
        }
    }
    visit[x][y]=false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> p[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            go(i,j,p[i][j],1);
            if(j<m-2){
                int tmp=p[i][j]+p[i][j+1]+p[i][j+2];
                if(i<n-1){
                    int result=tmp+p[i+1][j+1];
                    ans=max(ans, result);
                }
                if(i>0){
                    int result=tmp+p[i-1][j+1];
                    ans=max(ans, result);
                }
            }
            if(i<n-2){
                int tmp=p[i][j]+p[i+1][j]+p[i+2][j];
                if(j<m-1){
                    int result=tmp+p[i+1][j+1];
                    ans=max(ans, result);
                }
                if(j>0){
                    int result=tmp+p[i+1][j-1];
                    ans=max(ans, result);
                }
            }
        }
    }
    cout << ans;
}