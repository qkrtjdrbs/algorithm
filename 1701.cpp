#include <bits/stdc++.h>
using namespace std;
string p;
vector<int> F;

vector<int> makeF(string s){
    int begin = 1; int m = 0;
    int len = s.size();
    vector<int> v(len, 0);
    while(begin + m <= len){
        if(s[begin+m] == s[m]){
            ++m;
            v[begin+m-1] = m;
        } else{
            if(m == 0){
                ++begin;
            } else{
                begin += (m - v[m-1]);
                m = v[m-1];
            }
        }
    }
    return v;
}


int main(){
    getline(cin, p);
    int len = p.length();
    int ans = 0;
    for(int i=0;i<len;i++){
        string x = p.substr(i, len-i);
        F = makeF(x);
        for(auto x : F){
            ans = max(ans, x);
        }
    }
    cout << ans;
}