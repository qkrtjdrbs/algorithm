#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n, d[1001][1001];
void bfs(){
    queue<pair<int, int>> q;
    q.push({1,0});
    d[1][0]=0;
    while(!q.empty()){
        int s,c;
        tie(s, c)=q.front();
        q.pop();
        if(d[s][s]==-1){
            q.push({s,s});
            d[s][s]=d[s][c]+1;
        }
        if(s+c <= n && d[s+c][c]==-1){
            q.push({s+c,c});
            d[s+c][c]=d[s][c]+1;
        }
        if(s-1>=0 && d[s-1][c]==-1){
            q.push({s-1,c});
            d[s-1][c]=d[s][c]+1;
        }
    }
}

int main(){
    cin >> n;
    memset(d,-1,sizeof(d));
    bfs();
    int ans=-1;
    for(int i=0;i<=n;i++){
        if(d[n][i]!=-1){
            if(ans==-1 || ans>d[n][i])
                ans = d[n][i];
        }
    }
    cout << ans;
}