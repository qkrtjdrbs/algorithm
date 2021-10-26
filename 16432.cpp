#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[1001][10], isFound;
vector<int> v[1001], ans;

void go(int cur, int days){
    if(days == n){
        isFound = true;
        return;
    }
    for(auto next : v[days]){
        if(next != cur && !visited[days][next]){
            visited[days][next] = 1;
            ans.push_back(next);
            go(next, days+1);
            if(isFound) break;
            ans.pop_back();
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    go(0, 0);
    if(isFound){
        for(auto x : ans) cout << x << '\n';
    } else cout << -1;
}