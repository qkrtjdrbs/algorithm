#include <bits/stdc++.h>
using namespace std;

int n, s, d, cnt[100001];
vector<int> adj[100001];

int go1(int x, int px){
    for(auto next : adj[x]){
        if(next == px) continue;
        cnt[x] = max(cnt[x], 1 + go1(next, x));
    }
    return cnt[x];
}

int go2(int x, int px){
    int res = 0;
    for(auto next : adj[x]){
        if(next == px) continue;
        if(cnt[next] >= d) res += 1 + go2(next, x);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> s >> d;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go1(s, 0);
    cout << go2(s, 0)*2;
}