#include <bits/stdc++.h>
#define M 1234567891
using namespace std;
int n;
string s;

int main(){
    cin >> n >> s;
    long long ans = 0;
    long long r = 1;
    for(int i=0;i<s.length();i++){
        int x = s[i] - 'a';
        ans = (ans + (x+1) * r) % M;
        r = (r*31) % M;
    }
    cout << ans;
}