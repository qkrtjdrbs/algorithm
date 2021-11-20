#include <bits/stdc++.h>
using namespace std;

int n, k, cnt[21];
string st[300001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> st[i];
    int l=0, r=0;
    long long ans=0;
    for(r=0;r<=k;r++){
        int res = ++cnt[st[r].length()]; 
        ans += res - 1;   
    }
    while(r < n){
        --cnt[st[l++].length()];
        int res = ++cnt[st[r++].length()];
        ans += res - 1;
    }
    cout << ans;
}