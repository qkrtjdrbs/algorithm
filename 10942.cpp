#include <bits/stdc++.h>
using namespace std;
int n, m, a[2001], dp[2001][2001];

int go(int begin, int end){
    if(end <= begin){
        return 1;
    }
    if(dp[begin][end] == -1){
        if(a[begin] == a[end]){
            dp[begin][end] = go(begin+1, end-1);
        } else{
            dp[begin][end] = 0;
        }
    }
    return dp[begin][end];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    while(m--){
        int begin, end;
        cin >> begin >> end;
        cout << go(begin-1, end-1) << '\n';
    }
}