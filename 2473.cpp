#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, liq[5001], idx[3];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> liq[i];
    sort(liq, liq+n);
    ll res = 3000000001;
    for(int i=0;i<n-2;i++){
        int begin = i+1, end = n-1;
        while(begin < end){
            ll tmp = liq[i] + liq[begin] + liq[end];
            if(abs(tmp) < res){
                res = abs(tmp);
                idx[0] = i; idx[1] = begin; idx[2] = end;
            }
            if(tmp < 0) begin++;
            else end--;
        }
    }
    sort(idx, idx+3);
    for(int i=0;i<3;i++) cout << liq[idx[i]] << " ";
}