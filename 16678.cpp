#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long n, ans;

int main(){
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int t=1;
    for(int i=0;i<n;i++){
        if(v[i]>=t){
            ans += v[i]-t;
            t += 1;
        }
    }
    cout << ans;
}   