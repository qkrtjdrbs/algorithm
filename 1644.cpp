#include <bits/stdc++.h>
using namespace std;
int n, a[4000001];

int main(){
    vector<int> v;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    a[1] = 1;
    for(int i=2;i<=n;i++){
        if(a[i] == 1)
            continue;
        for(int j=i+i;j<=n;j+=i){
            a[j] = 1;
        }
    }
    for(int i=2;i<=n;i++){
        if(a[i] == 0){
            v.push_back(i);
        }
    }
    int begin = 0, end = 1, sum = v[0], ans = 0;
    int len = v.size();
    while(begin < end && end <= len && begin <= len){
        if(sum < n){
            sum += v[end++];
        } else if(sum > n){
            sum -= v[begin++];
        } else {
            ans++;
            sum -= v[begin++];
        }
    }
    cout << ans;
}