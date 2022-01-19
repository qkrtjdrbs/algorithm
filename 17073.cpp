#include <bits/stdc++.h>
using namespace std;

int n, w, node[500001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> w;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        node[a]++; node[b]++;
    }
    double cnt = 0;
    for(int i=2;i<=n;i++){
        if(node[i] == 1) cnt++;
    }
    cout.precision(6);
    cout << fixed << w / cnt;
}