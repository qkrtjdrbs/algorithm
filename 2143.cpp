#include <bits/stdc++.h>
using namespace std;

int t, n, m, aPsum[1001], bPsum[1001];
vector<int> av, bv;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    cin >> n;
    int tmp = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        tmp += x;
        aPsum[i] = tmp;
        av.push_back(tmp);
    }
    cin >> m;
    tmp = 0;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        tmp += x;
        bPsum[i] = tmp;
        bv.push_back(tmp);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            av.push_back(aPsum[i]-aPsum[j]);
        }
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<i;j++){
            bv.push_back(bPsum[i]-bPsum[j]);
        }
    }
    sort(av.begin(), av.end()); sort(bv.begin(), bv.end());
    long long ans = 0;
    for(auto x : av){
        auto l = lower_bound(bv.begin(), bv.end(), t-x);
        auto u = upper_bound(bv.begin(), bv.end(), t-x);
        ans += u - l;
    }
    cout << ans;
}