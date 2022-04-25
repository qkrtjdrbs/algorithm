#include <bits/stdc++.h>
using namespace std;

int t, n, ans=987;
bool visited[100001];
vector<string> v;

int cal(string a, string b){
    int res = 0;
    for(int i=0;i<4;i++){
        if(a[i] != b[i]) res++;
    }
    return res;
}

int dist(string s1, string s2, string s3){
    return cal(s1, s2) + cal(s1, s3) + cal(s2, s3);
}

void go(int idx, int len, int cnt){
    if(cnt == 3){
        vector<string> vec;
        for(int i=0;i<len;i++){
            if(visited[i]) vec.push_back(v[i]);
        }
        ans = min(ans, dist(vec[0], vec[1], vec[2]));
        return;
    }
    if(idx == len) return;
    visited[idx] = 1;
    go(idx+1, len, cnt+1);
    visited[idx] = 0;
    go(idx+1, len, cnt);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        memset(visited, 0, sizeof(visited));
        v.clear();
        ans = 987;
        for(int i=0;i<n;i++){
            string str;
            cin >> str;
            v.push_back(str);      
        }
        if(n > 32){
            cout << 0 << '\n';
        } else {
            go(0, n, 0);
            cout << ans << '\n';
        }
    }
}