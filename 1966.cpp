#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        deque<int> dq;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        int k = 1;
        while(!dq.empty()){
            int x = dq.front();
            bool flag = false;
            for(auto i : dq){
                if(x < i){
                    dq.push_back(x);
                    flag = true;
                    break;
                }
            }
            dq.pop_front();
            if(!flag){
                if(!m) {
                    cout << k << '\n';
                    break;
                }
                k++;
            }
            m = m - 1 < 0 ? dq.size()-1 : m - 1;
        }       
    }
}