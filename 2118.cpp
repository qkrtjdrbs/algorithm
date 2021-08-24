#include <bits/stdc++.h>
using namespace std;

int n, arr[50001], sum[50001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    int res = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        res += arr[i];
        sum[i] += res;
    }
    
}