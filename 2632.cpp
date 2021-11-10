#include <bits/stdc++.h>
using namespace std;

int pizza, n, m, a[1001], b[1001], aCnt[1000001], bCnt[1000001];
vector<int> aP, bP;

void makePartialSet(int arr[], int mx, vector<int> &v){
    for(int len=1;len<=mx;len++){
        int l=0, r=len-1, sum=0;
        for(int i=l;i<=r;i++) sum += arr[i];
        if(len == mx){
            v.push_back(sum);
            break;
        }
        while(l < mx){
            v.push_back(sum);
            sum -= arr[l++];
            if(r+1 == mx) r = 0;
            else r++;
            sum += arr[r];
        }
    }
    sort(v.begin(), v.end());
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> pizza >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    makePartialSet(a, n, aP); makePartialSet(b, m, bP);
    for(auto x : aP) aCnt[x]++;
    for(auto x : bP) bCnt[x]++;
    int ans = 0;
    ans += aCnt[pizza]; ans += bCnt[pizza];
    for(int i=1;i<pizza;i++){
        ans += aCnt[i] * bCnt[pizza-i];
    }
    cout << ans;
}