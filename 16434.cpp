#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, atk;
vector<tuple<int, int, int>> rooms;

bool go(ll maxHp){
    ll curHp = maxHp;
    ll curAtk = atk;
    for(auto room : rooms){
        int t, a, h;
        tie(t, a, h) = room;
        if(t == 1){
            ll wHits = (h / curAtk) + (h % curAtk ?  1 : 0);
            ll mHits = (curHp / a) + (curHp % a ? 1 : 0);
            if(mHits < wHits) return false;
            else {
                curHp -= (wHits - 1)* a;
            }
        } else {
            curHp = min(curHp + h, maxHp);
            curAtk += a;
        }
    }
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> atk;
    for(int i=0;i<n;i++){
        int t, a, h;
        cin >> t >> a >> h;
        rooms.push_back({t, a, h});
    }
    ll l = 1, r = 1e18;
    ll ans = r;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(go(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}