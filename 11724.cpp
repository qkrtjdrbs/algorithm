#include <iostream>
#include <vector>
using namespace std;
bool visit[1001];
vector<int> v[1001];
int com=0;
int n,m,a,b;
void dfs(int x) {
    for(int i=0;i<v[x].size();i++){
        if(!visit[v[x][i]]){
            visit[v[x][i]]=true;
            dfs(v[x][i]);
        }
    }
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            com+=1;
            dfs(i);
        }
    }
    cout << com;
}