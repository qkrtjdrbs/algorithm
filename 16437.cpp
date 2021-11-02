#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct island {
    char animal;
    int pop;
}Island;

int n;
Island island[1234567];
vector<int> adj[123457];

ll go(int x, int prev){
    ll sum = island[x].animal == 'S' ? island[x].pop : 0;
    for(auto next : adj[x]){
        if(next == prev) continue;
        sum += go(next, x);
    }
    if(island[x].animal == 'W'){
        sum > island[x].pop ? sum -= island[x].pop : sum = 0;
    }
    return sum;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=2;i<=n;i++){
        char t; int a, p;
        cin >> t >> a >> p;
        island[i] = {t, a};
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    cout << go(1, 0);
}