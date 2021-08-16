#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s;
vector<ll> v1, v2, res1, res2;

void go(int idx, int num, int bits, ll sum, bool flag){
    if(idx >= num){
        if(!flag){
            res1.push_back(sum);
        } else {
            res2.push_back(sum);
        }
        return;
    }
    if(!flag){
        go(idx+1, num, bits | (1 << idx), sum+v1[idx], flag);
        go(idx+1, num, bits, sum, flag);
    } else {
        go(idx+1, num, bits | (1 << idx), sum+v2[idx], flag);
        go(idx+1, num, bits, sum, flag);
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i=0;i<n/2;i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for(int i=0;i<n-n/2;i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    go(0, n/2, 1 << (n/2+1), 0, 0);
    go(0, n-n/2, 1 << (n-n/2+1), 0, 1);
    
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    reverse(res2.begin(), res2.end());

    int idx1 = 0, idx2 = 0;
    ll ans = 0;
    while(idx1 < res1.size() && idx2 < res2.size()){
        ll res = res1[idx1] + res2[idx2];
        if(res == s) {
            ll same1 = 1;
            ll same2 = 1;
            idx1++; idx2++;
            while(res1[idx1] == res1[idx1 - 1] && idx1 < res1.size()){
                same1++;
                idx1++;
            }
            while(res2[idx2] == res2[idx2 - 1] && idx2 < res2.size()){
                same2++;
                idx2++;
            }
            ans += same1 * same2;
        } else if(res > s) {
            idx2++;
        } else {
            idx1++;
        }
    }
    s == 0 ? cout << ans - 1 : cout << ans;
}