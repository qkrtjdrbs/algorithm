#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, visit[3000],dist[3000];
vector<int> v[3000];
int dfs(int cur, int prev)
{
    if (visit[cur] == 1)
    {
        return cur;
    }
    visit[cur] = 1;
    for (int next : v[cur])
    {
        if (next == prev)
            continue;
        int res = dfs(next, cur);
        if (res == -2)
            return -2;
        if (res >= 0)
        {
            visit[cur] = 2;
            if (cur == res)
                return -2;
            else
                return res;
        }
    }
    return -1;
}
void bfs(){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(visit[i]==2){
            q.push(i);
            dist[i]=0;
        }
        else{
            dist[i]=-1;
        }
    }
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int next : v[x]){
            if(dist[next]==-1){
                q.push(next);
                dist[next]=dist[x]+1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        a-=1; b-=1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, -1);
    bfs();
    for(int i=0;i<n;i++)
        cout << dist[i] << ' ';
}