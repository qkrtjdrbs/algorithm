#include <bits/stdc++.h>
using namespace std;

int n, arr[100001], psum[100001];
string s;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    if(n % 2 == 1){
        cout << 0;
        return 0;
    }
    s = "X" + s;
    
}
