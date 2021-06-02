#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int f, s, g, u, d, v[MAX];

int go(int s){
    queue<int> q;
    q.push(s);
    v[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == g){
            return v[cur] - 1;
        }
        int nextUp = cur + u;
        int nextDown = cur - d;
        if(1 <= nextUp && nextUp <= f && !v[nextUp]){
            v[nextUp] = v[cur] + 1;
            q.push(nextUp);
        }
        if(1 <= nextDown && nextDown <= f && !v[nextDown]){
            v[nextDown] = v[cur] + 1;
            q.push(nextDown);
        }
    }
    return -1;
}

int main(){
    cin >> f >> s >> g >> u >> d;
    int ans = go(s);
    if(ans == -1) cout << "use the stairs";
    else cout << ans;
}