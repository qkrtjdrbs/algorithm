#include <bits/stdc++.h>
using namespace std;

int n, m, parent[1001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x); y = Find(y);
    if(x == y) return false;
    else if(x < y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<=n;i++) parent[i] = i;
    priority_queue<tuple<int, int, int>> opq, ppq;
    for(int i=0;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(c) c = 0;
        else c = 1;
        opq.push({-c, a, b});
        ppq.push({c, a, b});
    }
    int ans1 = 0, ans2 = 0;
    while(!opq.empty()){
        int c, a, b;
        tie(c, a, b) = opq.top();
        opq.pop();
        c = -c;
        if(Union(a, b)) ans1 += c;
    }
    for(int i=0;i<=n;i++) parent[i] = i;
    while(!ppq.empty()){
        int c, a, b;
        tie(c, a, b) = ppq.top();
        ppq.pop();
        if(Union(a, b)) ans2 += c;
    }
    cout << pow(ans2, 2) - pow(ans1, 2);
}