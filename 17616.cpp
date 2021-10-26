#include <bits/stdc++.h>
using namespace std;

int n, m, x;
bool visited[100001];
vector<int> adj[100001], radj[100001];

int dfs(int cur, bool flag){
    visited[cur] = 1;
    int sum = 0;
    for(auto next : flag ? radj[cur] : adj[cur]){
        if(!visited[next]){
            sum += 1 + dfs(next, flag);
        }
    }
    return sum;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    cout << dfs(x, 1) + 1 << " " << n - dfs(x, 0);
}