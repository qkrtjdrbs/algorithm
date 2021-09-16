#include <bits/stdc++.h>
using namespace std;
int n;
long long up = 1, down = 1;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    int x;
    char op;
    for(int i=0;i<=2*(n-1);i++){
        if(i == 0){
            cin >> x;
            up *= x;
            continue;
        }
        if(i % 2 == 0){
            cin >> x;
            if(op == '*'){
                up *= x;
            } else if(op == '/'){
                down *= x;
            }
        } else {
            cin >> op;
        }
    }
    string ans;
    up % down == 0 ? ans = "mint chocolate" : ans = "toothpaste";
    cout << ans;
}