#include <bits/stdc++.h>
using namespace std;
int n, m, inDegree[100001];
vector<int> adj[32001];

void topologicalSort(){
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i] == 0){
            q.push(-i);
        }
    }
    for(int i=0;i<n;i++){
        int x = q.top();
        q.pop();
        cout << -x << " ";
        for(auto X : adj[-x]){
            if(--inDegree[X] == 0)
                q.push(-X);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int p, c;
        cin >> p >> c;
        adj[p].push_back(c);
        ++inDegree[c];
    }
    topologicalSort();
}