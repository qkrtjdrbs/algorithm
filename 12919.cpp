#include <bits/stdc++.h>
using namespace std;

string s, t;
bool flag;

void go(string res){
    if(res == s){
        flag = true;
        return;
    }
    if(flag) return;
    int len = res.size();
    if(len > 1 && res[len-1] == 'A'){
        go(res.substr(0, len-1));
    }
    if(len > 1 && res[0] == 'B'){
        reverse(res.begin(), res.end());
        go(res.substr(0, len-1));
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s >> t;
    go(t);
    cout << flag;
}