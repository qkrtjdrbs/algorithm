#include <iostream>
#include <queue>
using namespace std;
int n,m,go[101],dist[101];
void bfs(){
    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=1;i<=6;i++){
            if(dist[go[x+i]]==-1){
                q.push(go[x+i]);
                dist[go[x+i]]=dist[x]+1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=100;i++){
        go[i]=i;
        dist[i]=-1;
    }
    while(n--){
        int x, y;
        cin >> x >> y;
        go[x]=y;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        go[x]=y;
    }
    bfs();
    cout << dist[100];
}