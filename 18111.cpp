#include <bits/stdc++.h>
using namespace std;

int n, m, b, ans=987654321, mx;
vector<int> v;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int h=0;h<=256;h++){
        int tmp=b, res=0;
        bool flag = true;
        for(auto x : v){
            if(x > h){
                tmp += x - h;
                res += 2*(x - h);
            } else if(x < h){
                if(tmp < h - x){
                    flag = false;
                    break;
                }
                tmp -= (h - x);
                res += h - x;
            }
        }
        if(flag && ans >= res){
            ans = res;
            mx = h;
        }
    }
    cout << ans << ' ' << mx;
}