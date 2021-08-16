#include <bits/stdc++.h>
using namespace std;
int n, flag;
string s;

void go(int l, int r, int del){
    if(l > r){
        if(!del){
            flag = 0;
        } else {
            flag = 1;
        }
        return;
    }
    if(s[l] == s[r]){
        go(l+1, r-1, del);
    } else {
        if(!del){
            go(l+1, r, del+1);
            go(l, r-1, del+1);
        } else {
            return;
        }
    }
    
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        int l = 0, r = s.size()-1;
        int del = 0;
        flag = 2;
        go(l, r, 0);
        cout << flag << '\n';
    }
}
