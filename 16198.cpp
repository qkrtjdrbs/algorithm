#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,ans;
void go(vector<int> &w, int sum){
    int x=w.size();
    if(x==2){
        ans=max(ans, sum);
        return;
    }
    for(int i=1;i<x-1;i++){
        vector<int> next(w);
        next.erase(next.begin()+i);
        go(next,sum+w[i-1]*w[i+1]);
    }
}
int main(){
    cin >> n;
    vector<int> w(n);
    for(int i=0;i<n;i++)
        cin >> w[i];
    go(w,0);
    cout << ans;
}