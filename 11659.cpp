#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a;
vector<int> sum;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sum.push_back(a[0]);
    for(int i=1;i<n;i++){
        sum.push_back(a[i]+sum[i-1]);
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        int ans;
        x == 1 ? ans = sum[y-1] : ans = sum[y-1] - sum[x-2];
        cout << ans << '\n';
    }
}