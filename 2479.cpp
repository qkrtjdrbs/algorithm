#include <bits/stdc++.h>
using namespace std;

int n, k, s, e, parent[1001];
bool visited[1001];
vector<int> adj[1001];
string arr[1001];

bool bitsCheck(string a, string b){
    int cnt = 0;
    for(int i=0;i<k;i++){
        int x = a[i] - '0';
        int y = b[i] - '0';
        if(x != y) cnt++;
        if(cnt >= 2) return false;
    }
    if(cnt == 1) return true;
    return false;
}

void go(int start, int x){
    visited[x] = 1;
    if(x == start){
        for(int i=x;;i=parent[i]){
            cout << i << " ";
            if(i == e) break;
        }
        return;
    }
    for(auto next : adj[x]){
        if(!visited[next]) {
            parent[next] = x;
            go(start, next);
        }
    }
}

void bfs(){
    queue<pair<string, int>> q;
    q.push({arr[s], s});
    visited[s] = 1;
    while(!q.empty()){
        string x; int cur;
        tie(x, cur) = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(visited[i] || !bitsCheck(x, arr[i])) continue;
            q.push({arr[i], i});
            adj[cur].push_back(i);
            adj[i].push_back(cur);
            visited[i] = 1;
        }
    }
    if(!visited[e]) cout << -1;
    else {
        memset(visited, 0, sizeof(visited));
        go(s, e);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    cin >> s >> e;
    bfs();
}