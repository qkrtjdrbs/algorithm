#include <bits/stdc++.h>
using namespace std;
int num, A, B, a[100001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> a[i];
    }
    int left = 0, right = num-1;
    int ans = abs(a[left] + a[right]);
    while(left < right){
        int tmp = a[left] + a[right];
        if(abs(tmp) <= ans){
            ans = abs(tmp);
            A = a[left];
            B = a[right];
        }
        if(tmp < 0) {
            ++left;
        } else {
            --right;
        }
    }
    cout << A << " " << B;
}