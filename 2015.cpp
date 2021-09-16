#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, psum[200001];
ll ans;
map<int, ll> m;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> psum[i];
    for(int i=1;i<=n;i++) psum[i] += psum[i-1];
    for(int i=1;i<=n;i++){
        if(psum[i] == k) ans++;
        ans += m[psum[i]-k];
        m[psum[i]]++;
    }
    cout << ans;
}