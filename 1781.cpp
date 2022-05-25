#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        int dead, cup;
        cin >> dead >> cup;
        v.push_back({dead, cup});
    }
    sort(v.begin(), v.end());
    int ans=0, idx=n-1;
    for(int i=n;i>=1;i--){
        for(int j=idx;j>=0;j--){
            auto [dead, cup] = v[j];
            if(dead == i) pq.push(cup);
            else {
                idx = j;
                break;
            }
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}