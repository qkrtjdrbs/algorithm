#include <bits/stdc++.h>
using namespace std;

int n, m, comp[100001], ans[100001];
vector<int> adj[100001];

void go(int x, int sum){
    ans[x] = sum;
    for(auto next : adj[x]) go(next, sum+comp[next]);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(i == 1) continue;
        adj[x].push_back(i);
    }
    for(int i=0;i<m;i++){
        int idx, w;
        cin >> idx >> w;
        comp[idx] += w;
    }
    go(1, 0);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}