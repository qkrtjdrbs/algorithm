#include <bits/stdc++.h>
using namespace std;

int n, ans=-1, pos[49], p[49], s[49];
set<string> visited;

bool check(){
    for(int i=0;i<n;i++){
        if(p[pos[i]] != i % 3) return false;
    }
    return true;
}

void suffle(){
    int tmp[49];
    for(int i=0;i<n;i++){
        tmp[s[i]] = pos[i];
    }
    memcpy(pos, tmp, sizeof(tmp));
}

bool duplicate(){
    string str = "";
    for(int i=0;i<n;i++){
        str += to_string(pos[i]);
    }
    if(visited.find(str) != visited.end()) return true;
    visited.insert(str);
    return false;
}

void go(int cnt){
    if(check()){
        ans = cnt;
        return;
    }
    suffle();
    if(duplicate()) return;
    go(cnt+1);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++){
        cin >> s[i];
        pos[i] = i;
    }
    go(0);
    cout << ans;
}