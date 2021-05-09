#include <bits/stdc++.h>
using namespace std;
int n, work[10001], inDegree[10001], ans[10001];
vector<int> order[10001];

void go(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!inDegree[i])
            q.push(i);
    }
    while(!q.empty()){
        vector<int> v;
        int x = q.front();
        q.pop();

        for(auto X : order[x]){
            ans[X] = max(ans[X], work[X] + ans[x]);
            if(--inDegree[X] == 0){
                q.push(X);
            }
        }
    }
    int res = 0;
    for(auto x : ans){
        res = max(res, x);
    }
    cout << res;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int time, m;
        cin >> time >> m;
        work[i] = ans[i] = time;
        for(int j=0;j<m;j++){
            int first;
            cin >> first;
            order[first].push_back(i);
            ++inDegree[i];
        }
    }
    go();
}