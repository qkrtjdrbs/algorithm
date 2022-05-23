#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<n;i++){
        int op;
        cin >> op;
        if(!op){
            if(pq.empty()){
                cout << 0 << '\n';
            } else {
                auto [v, f] = pq.top();
                pq.pop();
                cout << v*f << '\n';
            }
        } else {
            int flag = op >= 0 ? -1 : 1;
            pq.push({-abs(op), flag});
        }
    }
}