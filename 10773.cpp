#include <bits/stdc++.h>
using namespace std;

int k;
stack<int> st;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> k;
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        if(!x) st.pop();
        else st.push(x);
    }
    int ans = 0;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans;
}