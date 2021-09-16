#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;
bool flag;
char chess[8][8];
int visit[8][8][9];
int dx[] = {0,0,1,-1,1,-1,1,-1,0};
int dy[] = {1,-1,0,0,1,1,-1,-1,0};
void bfs(){
    queue<tuple<int,int,int>> q;
    q.push({7,0,0});
    visit[7][0][0]=1;
    while(!q.empty()){
        int x,y,sec;
        tie(x,y,sec)=q.front(); q.pop();
        if(x==0 && y==7) {
            flag=true;
            return;
        }
        for(int i=0;i<9;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nt=min(sec+1,8);
            if(nx<0 || nx>=8 || ny<0 || ny>=8) continue;
            if(nx-sec>=0 && chess[nx-sec][ny]=='#') continue;
            if(nx-sec-1>=0 && chess[nx-sec-1][ny]=='#') continue;
            if(visit[nx][ny][nt]==0){
                visit[nx][ny][nt]=1;
                q.push({nx,ny,nt});
            }
        }
    }
}
int main(){
    for(int i=0;i<8;i++)
        cin >> chess[i];
    bfs();
    if(!flag) cout << 0;
    else cout << 1;
}