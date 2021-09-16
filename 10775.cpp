#include <iostream>
using namespace std;
int gate, p, parent[100001], ans;

int Find(int x){
    if(x==parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    int x = parent[a];
    int y = parent[b];
    parent[x] = y;
}

int main(){
    cin >> gate >> p;
    for(int i=0;i<=gate;i++)
        parent[i] = i;
    for(int i=1;i<=p;i++){
        int plane, emptyGate;
        cin >> plane;
        emptyGate = Find(plane);
        if(!emptyGate){
            break;
        } else {
            Union(emptyGate, emptyGate-1);
            ans += 1;
        }
    }
    cout << ans;
}