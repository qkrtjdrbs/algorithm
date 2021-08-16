#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[101];
vector<int> adj[101];
set<int> ans;

bool isOk(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : adj[x]){
            if(next == start) return true;
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    for(int i=1;i<=n;i++){
        memset(visited, false, sizeof(visited));
        if(isOk(i)) ans.insert(i);
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << '\n';
}