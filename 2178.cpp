#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,miro[100][100],visit[100][100];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int x, int y, int cnt){
    int ans=1;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x,y},cnt});
    visit[x][y]=cnt;
    while(!q.empty()){
        x=q.front().first.first;
        y=q.front().first.second;
        cnt=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int go_x=x+dx[k];
            int go_y=y+dy[k];
            int count=cnt+1;
            if(go_x >= 0 && go_x < n && go_y >= 0 && go_y <m){
                if(miro[go_x][go_y]==1 && visit[go_x][go_y]==987654321){
                    q.push({{go_x, go_y}, count});
                    visit[go_x][go_y]=count;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%1d",&miro[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visit[i][j]=987654321;
    }
    bfs(0,0,1);
    printf("%d",visit[n-1][m-1]);
}