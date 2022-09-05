#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[20010];
vector<int> adj[20010], info[20010];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1] = 1;
    while(!q.empty()){
        auto [cost, x] = q.front();
        q.pop();
        info[cost].push_back(x);
        for(auto nx : adj[x]){
            if(visited[nx]) continue;
            q.push({cost+1, nx});
            visited[nx] = 1;
        }
    }
    for(int i=0;i<=n;i++) sort(info[i].begin(), info[i].end());
    int a, b, c;
    for(int i=0;i<=n;i++){
        if(info[i].size()){
            a = info[i][0];
            b = i-1;
            c = info[i].size();
        }
    }
    cout << a << " " << b << " " << c;
}