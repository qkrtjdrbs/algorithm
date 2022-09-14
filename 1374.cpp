#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    priority_queue<pair<int, bool>> pq;
    for(int i=0;i<n;i++){
        int num, s, e;
        cin >> num >> s >> e;
        pq.push({-s, 0});
        pq.push({-e, 1});
    }
    int ans=1, res=0;
    while(!pq.empty()){
        auto [t, flag] = pq.top();
        pq.pop();
        if(!flag) res++;
        else res--;
        ans = max(ans, res);
    }
    cout << ans;
}