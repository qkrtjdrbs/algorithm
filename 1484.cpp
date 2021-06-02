#include <bits/stdc++.h>
using namespace std;
int G;
vector<int> ans;

int main(){
    cin >> G;
    int x = 1, y = 1;
    while(1){
        int f = x + y;
        int b = x - y;
        if(f * b == 0){
            if(x != 1 || y != 1)
                break;
        }
        if(f * b == G){
            ans.push_back(f-y);
            ++x;
        } else if(f * b > G){
            ++y;
        } else {
            ++x;
        }
    }
    if(ans.empty()){
        cout << -1;
        return 0;
    }
    for(auto X : ans){
        cout << X << '\n';
    }
}