#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v,e,k,dist[20001],visit[20001];

vector<pair<int, int>> M[20001];

void dijk(){
    for(int i=1;i<=v;i++){
        dist[i]=987654321;
    }
    dist[k]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});
    while(!pq.empty()){
        int cost=-pq.top().first;
        int newv=pq.top().second;
        pq.pop();
        if(visit[newv] == 1) continue;
        visit[newv] = 1;
        if(dist[newv]<cost) continue;
        for(int i=0;i<M[newv].size();i++){
            int cur=M[newv][i].first;
            int newdist=cost+M[newv][i].second;
            if(dist[cur] > newdist){
                dist[cur]=newdist;
                pq.push({-newdist, cur});
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(dist[i]==987654321)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int from, to, cost;
    cin >> v >> e >> k;
    for(int i=0;i<e;i++){
        cin >> from >> to >> cost;
        M[from].push_back({to, cost});
    }
    dijk();
}