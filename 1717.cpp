#include <bits/stdc++.h>
using namespace std;
int n, m, parent[1000001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    for(int i=0;i<m;i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 0){
            Union(a, b);
        } else {
            if(Find(a) == Find(b)){
                cout << "YES";
            } else {
                cout << "NO";
            }
            cout << '\n';
        }
    }
}