#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    priority_queue<ll> pq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        pq.push(-x);
    }
    for(int i=0;i<m;i++){
        ll x = pq.top();
        x = -x;
        pq.pop();

        ll y = pq.top();
        y = -y;
        pq.pop();

        pq.push(-(x+y));
        pq.push(-(x+y));
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans -= pq.top();
        pq.pop();
    }
    cout << ans;
}