#include <bits/stdc++.h>
using namespace std;
string t, p;
vector<int> F;
vector<int> ans;

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

void kmp(){
    int begin = 0; int m = 0;
    int tLen = t.size();
    int pLen = p.size();
    while(begin <= tLen - pLen){
        if(t[begin+m] == p[m]){
            ++m;
            if(m == pLen){
                ans.push_back(begin+1);
            }
        } else{
            if(m == 0){
                ++begin;
            } else{
                begin += (m - F[m-1]);
                m = F[m-1];
            }
        }
    }
}

int main(){
    getline(cin, t);
    getline(cin, p);
    F = makeF(p);
    kmp();
    int len = ans.size();
    cout << len << '\n';
    for(int i=0;i<len;i++)
        cout << ans[i] << '\n';
}