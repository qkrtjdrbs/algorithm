#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, a[100001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int start = 0, end = n-1;
    ll ans = a[start] + a[end];
    while(start < end){
        int tmp = a[start] + a[end];
        if(abs(tmp) <= abs(ans)){
            ans = tmp;
        }
        if(tmp < 0){
            start++;
        } else {
            end--;
        }
    }
    cout << ans;
}
