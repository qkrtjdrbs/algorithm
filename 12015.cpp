#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    v.push_back(-987654321);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(v.back() < x)
            v.push_back(x);
        else{
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }
    cout << v.size() - 1;
}