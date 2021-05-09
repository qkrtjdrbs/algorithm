#include <bits/stdc++.h>
using namespace std;
long long n, a[100001], d[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    long long height = 1;
    for(int i=0;i<n;i++){
        if(height <= a[i]){
            d[i] = height++;
        } else {
            if(a[i] < d[i-1]){
                d[i] = a[i];
                height = a[i];
            } else {
                d[i] = d[i-1];
                height = d[i];
            }
            height++;
        }
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, d[i]);
    }
    cout << ans;
}