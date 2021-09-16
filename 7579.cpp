#include <bits/stdc++.h>
using namespace std;
int n, m, a[101], c[101], d[101][10001];

int go(int idx, int addC){
    int &res = d[idx][addC];
    if(idx >= n){
        return 0;
    }
    if(res != -1)
        return res;
    res = go(idx+1, addC);
    if(c[idx] <= addC)
        res = max(res, a[idx]+go(idx+1, addC-c[idx]));
    return res;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> c[i];
    memset(d, -1, sizeof(d));
    int addC = 0;
    while(1){
        if(go(0, addC) >= m) {
            cout << addC;
            break;
        }
        addC++;
    }
}