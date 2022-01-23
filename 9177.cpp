#include <bits/stdc++.h>
using namespace std;

int n;
string a, b, c;
bool flag;

void go(int aIdx, int bIdx, int cIdx){
    if(cIdx == -1){
        flag = true;
        return;
    }
    if(flag) return;
    if(aIdx >= 0 && c[cIdx] == a[aIdx]) go(aIdx-1, bIdx, cIdx-1);
    if(bIdx >= 0 && c[cIdx] == b[bIdx]) go(aIdx, bIdx-1, cIdx-1);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b >> c;
        flag = false;
        go(a.size()-1, b.size()-1, c.size()-1);
        cout << "Data set " << i << ": " << (flag ? "yes" : "no") << '\n';
    }
}