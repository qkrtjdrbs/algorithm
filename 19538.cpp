#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[200001], visited[200001];
vector<int> adj[200001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        while(1){
            cin >> x;
            if(!x) break;
            adj[i].push_back(x);
        }
    }
    cin >> m;
    queue<pair<int, int>> q;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        q.push({x, 1});
        visited[x] = 1;
    }
    while(!q.empty()){
        int x, t;
        tie(x, t) = q.front();
        q.pop();
        for(auto next : adj[x]){
            if(visited[next]) continue;
            int friends = adj[next].size();
            cnt[next]++;
            if(friends % 2 == 0 && cnt[next] >= friends / 2){
                q.push({next, t+1});
                visited[next] = t+1;
            } else if(friends % 2 != 0 && cnt[next] > friends / 2) {
                q.push({next, t+1});
                visited[next] = t+1;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << --visited[i] << " ";
}