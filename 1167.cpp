#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n,d[100001];
bool visit[100001];
vector<pair<int, int>> V[100001];
void bfs(int start){
    memset(d,0,sizeof(d));
    memset(visit,0,sizeof(visit));
    queue<int> q;
    q.push(start);
    visit[start]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y=0;y<V[x].size();y++){
            if(!visit[V[x][y].first]){
                visit[V[x][y].first]=true;
                d[V[x][y].first] = d[x]+V[x][y].second;
                q.push(V[x][y].first);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        int ver,edge,dist;
        cin >> ver;
        while(1){
            cin >> edge;
            if(edge==-1) break;
            cin >> dist;
            V[ver].push_back({edge, dist});
            V[edge].push_back({ver, dist});
        }
    }
    bfs(1);
    int start=1;
    for(int i=2;i<=n;i++){
        if(d[i]>d[start])
            start=i;
    }
    bfs(start);
    int ans=d[1];
    for(int i=2;i<=n;i++){
        if(d[i]>ans)
            ans=d[i];
    }
    cout << ans;
}