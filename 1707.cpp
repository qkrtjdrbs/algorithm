#include <iostream>
#include <vector>
using namespace std;
int visit[20001];
int k,v,e,a,b;
vector<int> ver[20001];
void dfs(int x, int c) {
    visit[x]=c;
    for(int i=0;i<ver[x].size();i++){
        if(!visit[ver[x][i]]){
            dfs(ver[x][i],3-c);
        }
    }
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> k;
    while(k--){
        cin >> v >> e;
        for (int i=1; i<=v; i++) {
            ver[i].clear();
            visit[i] = 0;
        }
        for(int i=0;i<e;i++){
            cin >> a >> b;
            ver[a].push_back(b);
            ver[b].push_back(a);
        }
        for (int i=1; i<=v; i++) {
            if (visit[i] == 0) {
                dfs(i, 1);
            }
        }
        bool sign=true;
        for(int i=1;i<=v;i++){
            for(int j=0;j<ver[i].size();j++){
                int k=ver[i][j];
                if(visit[i]==visit[k]){
                    sign=false;
                }
            }
        }
        if(!sign)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}