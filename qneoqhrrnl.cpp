#include <bits/stdc++.h>
using namespace std;

int n, visited[100001];
vector<int> adj[100001];

void bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 1});
    visited[start] = 1;
    while(!q.empty()){
        auto [x, cost] = q.front();
        q.pop();
        for(auto next : adj[x]){
            if(!visited[next]){
                visited[next] = cost+1;
                q.push({next, cost+1});
            }
        }
    }
}

vector<int> solution(int nn, vector<vector<int>> roads, vector<int> s, int e) {
    vector<int> ans;
    for(auto road : roads){
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }
    bfs(e);
    for(auto x : s){
        ans.push_back(visited[x]-1);
    }
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    solution(5, {{1, 2}, {1, 4}, {2, 4}, {2, 5}, {4, 5}}, {1, 3, 5}, 5);
}