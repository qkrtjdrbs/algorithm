#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    priority_queue<int, vector<int>, greater<int>> pq1;
    priority_queue<int> pq2;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(pq1.size() == pq2.size()) pq2.push(num);
        else pq1.push(num);
        
        if(!pq1.empty() && !pq2.empty() && pq1.top() < pq2.top()){
            int mn = pq1.top(); pq1.pop();
            int mx = pq2.top(); pq2.pop();
            pq1.push(mx); pq2.push(mn);
        }

        cout << pq2.top() << '\n';
    }
}