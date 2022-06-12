#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        priority_queue<ll> pq;
        cin >> n;
        for(int i=0;i<n;i++){
            int file;
            cin >> file;
            pq.push(-file);
        }
        ll ans = 0;
        while(!pq.empty()){
            ll a = -pq.top(); pq.pop();
            ll b = -pq.top(); pq.pop();
            ll res = a + b;
            ans += res;
            if(!pq.empty()) pq.push(-res);
        }
        cout << ans << '\n';
    }
}