#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
int t, parent[MAX], cnt[MAX];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y) {    
        if(cnt[x] < cnt[y]) swap(x, y);
        parent[y] = x;
        cnt[x] += cnt[y];
        cnt[y] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> t;
    while(t--){
        map<string, int> m;
        int n;
        cin >> n;
        for(int i=0;i<=MAX;i++){
            parent[i] = i;
            cnt[i] = 1;
        }
        int idx = 1;
        for(int i=0;i<n;i++){
            string a, b;
            cin >> a >> b;
            if(m.count(a) == 0) m[a] = idx++;
            if(m.count(b) == 0) m[b] = idx++;
            int p1 = Find(m[a]);
            int p2 = Find(m[b]);
            if(p1 == p2) cout << max(cnt[p1], cnt[p2]) << '\n';
            else {
                Union(p1, p2);
                cout << max(cnt[p1], cnt[p2]) << '\n';
            }
        }
    }
}