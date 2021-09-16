#include <bits/stdc++.h>
#define MAX 1600002
using namespace std;
int n, t[MAX], p[MAX], d[MAX];


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> p[i];
    }
    for(int i=1;i<=n;i++){
        d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
        d[i+1] = max(d[i+1], d[i]);
    }
    cout << d[n+1];
}