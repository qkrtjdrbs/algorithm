#include <bits/stdc++.h>
using namespace std;

int n, psum[100001][4], cnt[81];
string s;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> s;
    s = "X" + s;
    for(int i=1;i<=n;i++){
        if(s[i] == 'T') psum[i][0]++;
        else if(s[i] == 'G') psum[i][1]++;
        else if(s[i] == 'F') psum[i][2]++;
        else psum[i][3]++;
        psum[i][0] += psum[i-1][0];
        psum[i][1] += psum[i-1][1];
        psum[i][2] += psum[i-1][2];
        psum[i][3] += psum[i-1][3];
    }
    for(int i=1;i<=n;i++){
        int bits = 27*(psum[i][0] % 3) + 9*(psum[i][1] % 3) + 3*(psum[i][2] % 3) + psum[i][3] % 3;
        cnt[bits]++;
    }
    long long ans = 0;
    cnt[0]++;
    for(int i=0;i<81;i++){
        if(cnt[i] >= 2){
            for(int j=1;j<cnt[i];j++) ans += j;
        }
    }
    cout << ans;
}