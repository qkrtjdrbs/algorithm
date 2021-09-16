#include <bits/stdc++.h>
using namespace std;
int n,e,k,f,dist[1001],parent[1001];
vector<pair<int, int>> M[100001];

void backtraking(int x, int cnt){
    if(x == parent[x]){
        cout << cnt << '\n';
        cout << x << " ";
        return;
    }
    else backtraking(parent[x], cnt+1);
    cout << x << " ";
}

void dijk(int start, int end){
    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
    }
    dist[start]=0;
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, start, start});
    while(!pq.empty()){
        int cost, vertex, P;
        tie(cost, vertex, P) = pq.top();
        pq.pop();
        cost *= -1;
        if(dist[vertex]<cost) continue;
        parent[vertex] = P;
        for(int i=0;i<M[vertex].size();i++){
            int cur=M[vertex][i].first; 
            int newdist=cost+M[vertex][i].second;
            if(dist[cur] > newdist){
                dist[cur]=newdist;
                pq.push({-newdist, cur, vertex});
            }
        }
    }
    cout << dist[end] << '\n';
    backtraking(end, 1);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int from, to, cost;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> from >> to >> cost;
        M[from].push_back({to, cost});
    }
    cin >> k >> f;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    dijk(k, f);
}