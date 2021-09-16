#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt=0;
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(){
    cin >> n;
    vector<pair<int, int>> I(n);
    for(int i=0;i<n;i++)
        cin >> I[i].first >> I[i].second;
    sort(I.begin(), I.end(), cmp);
    int select = 0;
    for(auto x : I){
        if(select <= x.first){
            select = x.second;
            cnt += 1;
        }
    }
    cout << cnt;
}