#include <bits/stdc++.h>
using namespace std;

int t, k;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        map<int, int> m;
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        cin >> k;
        for(int i=0;i<k;i++){
            char op;
            int num;
            cin >> op >> num;
            if(op == 'I'){
                if(m.find(num) == m.end()){
                    m.insert({num, 1});
                } else {
                    m[num]++;
                }
                pq1.push(num);
                pq2.push(num);
            } else if(op == 'D'){
                if(num == 1){
                    while(!pq1.empty()){
                        int n = pq1.top();
                        pq1.pop();
                        if(m[n] != 0){
                            m[n]--;
                            break;
                        }
                    }
                } else {
                    while(!pq2.empty()){
                        int n = pq2.top();
                        pq2.pop();
                        if(m[n] != 0){
                            m[n]--;
                            break;
                        }
                    }
                }
            }
        }
        long long mx=LLONG_MIN, mn=LLONG_MAX;
        while(!pq1.empty()){
            long long n = pq1.top();
            pq1.pop();
            if(m[n] != 0){
                mx = max(mx, n);
                mn = min(mn, n);
            }
        }
        if(mx == LLONG_MIN) cout << "EMPTY\n";
        else cout << mx << " " << mn << '\n';
    }
}