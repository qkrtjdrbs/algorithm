#include <bits/stdc++.h>
using namespace std;

vector<int> ddr;
int dp[5][5][100001]; //왼, 오, i번째
int power[5][5] = {{0,2,2,2,2}, {0,1,3,4,3}, {0,3,1,3,4}, {0,4,3,1,3}, {0,3,4,3,1}};

int go(int l, int r, int idx, int len){
    if(idx == len) return 0;
    int &res = dp[l][r][idx];
    if(res) return res;
    return res = min(power[l][ddr[idx]]+go(ddr[idx], r, idx+1, len), power[r][ddr[idx]]+go(l, ddr[idx], idx+1, len));
}

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    while(1){
        int x;
        cin >> x;
        if(!x) break;
        ddr.push_back(x);
    }
    int len = ddr.size();
    cout << go(0, 0, 0, len);
}