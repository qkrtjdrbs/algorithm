#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[27];

bool go(int x, int dest){
    if(x == dest) return true;
    bool res = false;
    for(auto next : adj[x]) res = go(next, dest);
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n; cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        getline(cin, s);
        string a = s.substr(0, 1);
        string b = s.substr(5);
        int x = a[0] - 'a';
        int y = b[0] - 'a';
        adj[x].push_back(y);
    }
    cin >> m; cin.ignore();
    for(int i=0;i<m;i++){
        string s;
        getline(cin, s);
        string a = s.substr(0, 1);
        string b = s.substr(5);
        int x = a[0] - 'a';
        int y = b[0] - 'a';
        if(go(x, y)) cout << "T\n";
        else cout << "F\n";
    }
}