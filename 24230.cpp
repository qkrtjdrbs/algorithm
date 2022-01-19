#include <bits/stdc++.h>
using namespace std;

int n, wanted[200001];
vector<int> adj[200001];

int go(int idx, int prev, int color){
    int res = 0;
    if(color != wanted[idx]){
        res++;
        color = wanted[idx];
    }
    for(auto next : adj[idx]){
        if(next == prev) continue;
        res += go(next, idx, color);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> wanted[i];
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << go(1, 0, 0);
}