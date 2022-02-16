#include <bits/stdc++.h>
using namespace std;

int visited[101], r;
string s;

void go(string str, int offset){
    if(!str.size()) return;
    char mn = str[0];
    int idx = 0;
    for(int i=0;i<str.size();i++){
        if(visited[i+offset]) continue;
        if(str[i] < mn){
            mn = str[i];
            idx = i;
        }
    }
    visited[idx+offset] = ++r;
    go(str.substr(idx+1), offset+idx+1);
    go(str.substr(0, idx), offset);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    go(s, 0);
    for(int k=1;k<=s.size();k++){
        for(int i=0;i<s.size();i++){
            if(visited[i] <= k) cout << s[i];
        }
        cout << '\n';
    }
}