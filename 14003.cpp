#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<pair<int, int>> ans;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, data, maxIdx=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        if (i == 0) {
            v.push_back(data);
            ans.push_back({0, data});
            continue;
        }
        if (v.back() < data) {
            v.push_back(data);
            int idx = v.size()-1;
            ans.push_back({idx, data});
            maxIdx = max(maxIdx, idx);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), data) - v.begin();
            v[it] = data;
            ans.push_back({it, data});
            maxIdx = max(maxIdx, (int)it);
        }
    } 
    stack<int> st;
    cout << v.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto x : ans){
        if(x.first == maxIdx){
            st.push(x.second);
            maxIdx--;
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
