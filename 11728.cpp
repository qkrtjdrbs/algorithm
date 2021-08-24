#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000001], b[1000001];
vector<int> ans;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int ai = 0, bi = 0;
    while(ai < n && bi < m){
        if(a[ai] > b[bi]){
            ans.push_back(b[bi++]);
        } else if(a[ai] < b[bi]) {
            ans.push_back(a[ai++]);
        } else {
            ans.push_back(a[ai++]);
            ans.push_back(b[bi++]);
        }
    }
    while(ai < n) ans.push_back(a[ai++]);
    while(bi < m) ans.push_back(b[bi++]);
    for(auto x : ans) cout << x << " ";
}