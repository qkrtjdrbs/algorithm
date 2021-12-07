#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[300001];
vector<int> adj[300001];

void go(int idx){
    visited[idx] = 1;
    for(auto next : adj[idx]){
        if(!visited[next]) go(next);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n-2;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            go(i);
            break;
        }
    }
    bool x = visited[1];
    for(int i=2;i<=n;i++){
        if(visited[i] != x){
            cout << 1 << " " << i;
            break;
        }
    }
}