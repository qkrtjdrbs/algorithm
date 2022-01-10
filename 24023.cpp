#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    int tmp = 0, l = 1;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if((x | k) != k){
            tmp = 0;
            l = i + 1;
        } else {
            tmp |= x;
            if(tmp == k){
                cout << l << " " << i;
                return 0;
            }
        }
    }
    cout << -1;
}