#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
int n, Visit[MAX], d[MAX][2];
vector<int> adj[MAX];
vector<int> adj2[MAX];

void makeTree(int x){
    Visit[x] = 1;
    for(auto X : adj[x]){
        if(!Visit[X]){
            adj2[x].push_back(X);
            makeTree(X);
        }
    }
}

int go(int x, int isE){
    int &res = d[x][isE];
    if(res != -1) return res;
    res = 0;
    if(isE){
        ++res;
        for(auto X : adj2[x]){
            res += min(go(X, 0), go(X, 1));
        }
    } else {
        for(auto X : adj2[x]){
            res += go(X, 1);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    makeTree(1);
    memset(d, -1, sizeof(d));
    cout << min(go(1, 0), go(1, 1));
}