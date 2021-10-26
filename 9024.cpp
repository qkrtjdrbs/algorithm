#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int n, k, res = 987654321;
        cin >> n >> k;
        vector<int> arr(n, 0);
        map<int, int> m;
        for(int i=0;i<n;i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int l = 0, r = n-1;
        while(l < r){
            int sum = arr[l] + arr[r];
            m[sum]++;
            if(res > abs(sum - k)){
                res = abs(sum - k);
            }
            if(sum > k){
                r--;
            } else if(sum < k){
                l++;
            } else {
                r--; l++;
            }
        }
        res == 0 ? cout << m[k] : cout << m[k-res] + m[k+res];
        cout << '\n';
    }
}