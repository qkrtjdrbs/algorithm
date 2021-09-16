#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
map<string, priority_queue<int>> m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x, k;
        string gName;
        cin >> x >> gName >> k;
        if(x == 1){
            for(int j=0;j<k;j++){
                int v;
                cin >> v;
                m[gName].push(v);
            }
        } else {
            for(int j=0;j<k;j++){
                if(m[gName].empty()) break;
                ans += m[gName].top();
                m[gName].pop();
            }
        }
    }
    cout << ans;
}