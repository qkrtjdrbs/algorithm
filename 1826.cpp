#include <bits/stdc++.h>
using namespace std;

int n, l, p;
pair<int, int> info[10001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        info[i] = {a, b};
    }
    cin >> l >> p;
    sort(info, info+n);
    priority_queue<int> pq;
    int ans=0, idx=0;
    while(p < l){
        while(idx < n && info[idx].first <= p){
            pq.push(info[idx++].second);
        }
        if(pq.empty()){
            ans = -1;
            break;
        }
        p += pq.top();
        pq.pop();
        ans++;
    }
    cout << ans;
}