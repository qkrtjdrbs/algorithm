#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[100000];
int n, order[100000], visit[100000], parent[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        a-=1; b-=1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >> order[i];
        order[i]-=1;
    }
    queue<int> q;
    q.push(0);
    visit[0]=1;
    int m=1;
    for(int i=0;i<n;i++){
        if(q.empty()){
            cout << 0;
            return 0;
        }
        int cnt=0;
        int x=q.front(); q.pop();
        if(x!=order[i]){
            cout << 0;
            return 0;
        }
        for(int y : v[x]){
            if(visit[y]==0){
               parent[y]=x;
               cnt+=1; 
            }
        }
        for(int j=0;j<cnt;j++){
            if(m+j >= n || parent[order[j+m]]!=x){
                cout << "0";
                return 0;
            }
            q.push(order[m+j]);
            visit[order[m+j]]=1;
        }
        m+=cnt;
    }
    cout << 1;
}