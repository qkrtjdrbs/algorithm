#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[10001];
bool visited[10001];
vector<int> adj[10001];

int go(int x){
    int res = 0;
    for(auto next : adj[x]){
        if(!visited[next]){
            visited[next] = 1;
            res += 1+go(next);
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        int res = go(i)+1;
        mx = max(mx, res);
        cnt[i] = res;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i] == mx) cout << i << ' ';
    }
}