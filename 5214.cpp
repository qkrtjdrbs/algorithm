#include <bits/stdc++.h>
using namespace std;

int n, k, m, refer[100001];
bool visited[100001];
vector<int> adj[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k >> m;
    for(int i=0;i<m;i++){
        int st[1001] = {0,};
        for(int j=0;j<k;j++){
            cin >> st[j];
            refer[st[j]]++;
        }
        for(int j=1;j<k-1;j++){
            adj[st[j]].push_back(st[j-1]);
            adj[st[j]].push_back(st[j+1]);
            adj[st[j-1]].push_back(st[j]);
            adj[st[j+1]].push_back(st[j]);
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    visited[1] = 1;
    while(!pq.empty()){
        int cnt, cur;
        tie(cnt, cur) = pq.top();
        pq.pop();
        if(cur == n){
            cout << cnt+2;
            return 0;
        }
        for(auto next : adj[cur]){
            if(!visited[next]){
                if(refer[next] == 1){
                    pq.push({cnt, next});
                } else {
                    pq.push({cnt+1, next});
                }
                visited[next] = 1;
            }
        }
    }
    cout << -1;
}