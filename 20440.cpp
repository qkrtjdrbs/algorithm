#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int s, e; cin >> s >> e;
        v.push_back({s, +1});
        v.push_back({e, -1});
    }
    sort(v.begin(), v.end());
    int l = -1, r = -1;
    int sum = 0, mx = 0;
    for(int i=0;i<2*N;i++) {
        sum += v[i].second;
        mx = max(mx, sum);
    }

    for(int i=0;i<2*N;i++) {
        sum += v[i].second;
        if(i + 1 < 2*N && v[i+1].first == v[i].first) continue;
        if(l == -1) {
            if(sum == mx) {
                l = v[i].first;
            }
        } else if(sum < mx) {
            r = v[i].first;
            break;
        }
    }
    cout << mx << '\n';
    cout << l << " " << r;
}