#include <bits/stdc++.h>
using namespace std;
int n, m, x, dist[1001];
vector<pair<int, int>> M[10001];

void initDist(){
    for(int i=1;i<=n;i++){
        dist[i] = 987654321;
    }
}

void clearQueue(priority_queue<pair<int, int>> &someQueue)
{
    priority_queue<pair<int, int>> empty;
    swap(someQueue, empty);
}


int dijk(int start){
    int res = 0;
    priority_queue<pair<int ,int>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cost, vertex;
        tie(cost, vertex) = pq.top();
        cost *= -1;
        pq.pop();
        if(vertex == x) break;
        for(auto i : M[vertex]){
            int toV, newC;
            tie(toV, newC) = i;
            if(dist[toV] > cost + newC){
                dist[toV] = cost + newC;
                pq.push({-(cost+newC), toV});
            }
        }
    }
    res += dist[x];

    clearQueue(pq);
    initDist();

    pq.push({0, x});
    while(!pq.empty()){
        int cost, vertex;
        tie(cost, vertex) = pq.top();
        cost *= -1;
        pq.pop();
        if(vertex == start) break;
        for(auto i : M[vertex]){
            int toV, newC;
            tie(toV, newC) = i;
            if(dist[toV] > cost + newC){
                dist[toV] = cost + newC;
                pq.push({-(cost+newC), toV});
            }
        }
    }
    res += dist[start];
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        M[from].push_back({to, cost});
    }
    int ans = -1;
    for(int i=1;i<=n;i++){
        if(i == x) continue;
        initDist();
        ans = max(ans, dijk(i));
    }
    cout << ans;
}