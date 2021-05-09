#include <bits/stdc++.h>
using namespace std;
int n, m, Visit[201], flag;
vector<int> adj[201];
vector<int> q;

void dfs(int x, int end){
    if(x == end){
        flag = 1;
        return;
    }
    Visit[x] = 1;
    for(auto X : adj[x]){
        if(Visit[X] <= 0){
            dfs(X, end);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            if(x == 1){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        q.push_back(x-1);
    }
    int len = q.size();
    for(int i=0;i<len-1;i++){
        flag = 0;
        dfs(q[i], q[i+1]);
        if(!flag){
            cout << "NO";
            return 0;
        }
        memset(Visit, -1, sizeof(Visit));
    }
    cout << "YES";
}