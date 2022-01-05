#include <bits/stdc++.h>
using namespace std;

int d, n;
vector<int> arr;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> d >> n;
    int tmp = INT_MAX;
    for(int i=0;i<d;i++){
        int x;
        cin >> x;
        tmp = min(tmp, x);
        arr.push_back(tmp);
    }
    auto l = arr.begin();
    auto r = arr.end();
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        r = upper_bound(l, r, p, greater<int>());
        r--;
    }
    int ans = r - arr.begin() + 1;
    cout << ans;
}