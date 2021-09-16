#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
int n, s[MAX], d[MAX];

int Jump(int idx){
    if(idx <= 0 || idx > n) return 0;
    if(d[idx] == -1) return d[idx];
    d[idx] = 1 + max(Jump(idx+s[idx]), Jump(idx-s[idx]));
    return d[idx];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    int start;
    cin >> start;
    int ans = Jump(start);
    cout << ans;
}