#include <bits/stdc++.h>
using namespace std;

int n, ans=987654321, mp, mf, ms, mv;
bool visited[16];

typedef struct food {
    int p, f, s, v, c;
}Food;

vector<int> idxs;
vector<Food> foods;

void putIdxs(){
    idxs.clear();
    for(int i=0;i<n;i++){
        if(visited[i]) idxs.push_back(i+1);
    }
}

bool check(){
    vector<int> tmp;
    for(int i=0;i<n;i++){
        if(visited[i]) tmp.push_back(i+1);
    }
    for(int i=0;i<n;i++) tmp.push_back(0);
    for(int i=0;i<n;i++){
        if(idxs[i] > tmp[i]) return true;
        if(idxs[i] < tmp[i]) return false;
    }
    return false;
}

void go(int idx, int p, int f, int s, int v, int c){
    if(idx == n){
        if(ans < c) return;
        if(p < mp || f < mf || s < ms || v < mv) return;
        if(ans > c){
            ans = c;
            putIdxs();
        } else if(ans == c && check()){
            putIdxs();
        }
        return;
    }
    visited[idx] = 1;
    go(idx+1, p+foods[idx].p, f+foods[idx].f, s+foods[idx].s, v+foods[idx].v, c+foods[idx].c);
    visited[idx] = 0;
    go(idx+1, p, f, s, v, c);
}
int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> mp >> mf >> ms >> mv;
    for(int i=0;i<n;i++){
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        foods.push_back({p, f, s, v, c});
    }   
    go(0, 0, 0, 0, 0, 0);
    if(!idxs.size()){
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    for(auto i : idxs) cout << i << " ";
}