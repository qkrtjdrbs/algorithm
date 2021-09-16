#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int f[2000][2000];
vector<int> v[2000];
vector<pair<int, int>> e;
int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        f[a][b]=1; f[b][a]=1;
        v[a].push_back(b); v[b].push_back(a);
        e.push_back({a,b});
        e.push_back({b,a});
    }
    m*=2;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            int A = e[i].first;
            int B = e[i].second;
            int C = e[j].first;
            int D = e[j].second;
            if(A==B || A==C || A==D || B==C || B==D || C==D)
                continue;
            if(!f[B][C])
                continue;
            for(int E : v[D]){
                if(A==E || B==E || C==E || D==E)
                    continue;
                else{
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}