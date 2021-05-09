#include <bits/stdc++.h>
using namespace std;
int n, m, d[1001];
vector<int> adj[1001];
vector<int> ans;

void go(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(d[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){   
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        ++cnt;
        for(auto next : adj[cur]){
            if(--d[next] == 0){
                q.push(next);
            }
        }
    }
    if(q.empty() && cnt != n){
        cout << 0;
        return;
    } else {
        for(auto X : ans){
            cout << X << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        int a[k];
        for(int j=0;j<k;j++){
            cin >> a[j];
        }
        for(int j=0;j<k-1;j++){
            adj[a[j]].push_back(a[j+1]);
            ++d[a[j+1]];
        }
    }
    go();
}
