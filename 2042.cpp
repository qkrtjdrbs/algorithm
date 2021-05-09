#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<long long> a;
vector<long long> sum;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sum.push_back(a[0]);
    for(int i=1;i<n;i++){
        sum.push_back(a[i]+sum[i-1]);
    }
    for(int i=0;i<m+k;i++){
        long long a, b, c;
        cin >> a >> b >> c;
    }
}