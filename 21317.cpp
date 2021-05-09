#include <bits/stdc++.h>
using namespace std;
int n, k, ans=987654321;
vector<pair<int, int>> stone;

void go(int idx, int sum, int veryBig){
    if(idx == n-1){
        ans = min(ans, sum);
        return;
    }
    if(idx > n-1){
        return;
    }
    int small, big;
    tie(small, big) = stone[idx];
    if(veryBig == 0){
        go(idx+1, sum+small, 0);
        go(idx+2, sum+big, 0);
        go(idx+3, sum+k, 1);
    } else {
        go(idx+1, sum+small, 1);
        go(idx+2, sum+big, 1);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int small, big;
        cin >> small >> big;
        stone.push_back({small, big});
    }
    cin >> k;
    go(0, 0, 0);
    go(0, 0, 1);
    cout << ans;
}