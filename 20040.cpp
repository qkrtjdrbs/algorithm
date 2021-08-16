#include <bits/stdc++.h>
using namespace std;

int n, m, parent[500000];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(!Union(a, b)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}