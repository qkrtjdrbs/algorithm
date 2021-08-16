#include <bits/stdc++.h>
using namespace std;
set<string> s;

int main(){
    while(1){
        string x;
        cin >> x;
        if(x == "0"){
            break;
        }
        s.insert(x);
    }
    for(auto x : s){
        cout << x << " ";
    }
}