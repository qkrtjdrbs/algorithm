#include <bits/stdc++.h>
using namespace std;
int n, start, ans, v[51];
vector<int> adj[51];

void go(int x){
    v[x] = 1;
    if(adj[x].empty()){
        ans++;
        return;
    }
    for(auto next : adj[x]){
        if(v[next] == -1 && adj[x].size() == 1){
            ans++;
            break;
        }
        if(!v[next]){
            go(next);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == -1) {
            start = i;
            continue;
        }
        adj[x].push_back(i);
    }
    int d;
    cin >> d;
    v[d] = -1;
    if(v[start] != -1)
        go(start);
    cout << ans;
}