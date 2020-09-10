#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> v[100000];
vector<int> ans;
int n, order[100000], visit[100000], t[100000];
void dfs(int x) {
    if(visit[x]==false){
        ans.push_back(x);
    }
    if (visit[x] == true) {
        return;
    }
    visit[x] = true;
    for (int y : v[x]) {
        if (visit[y] == false) {
            dfs(y);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a -= 1;
        b -= 1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i] -= 1;
        order[t[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        sort(v[i].begin(), v[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    dfs(0);
    for(int i=0;i<n;i++){
        if(ans[i]!=t[i]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}