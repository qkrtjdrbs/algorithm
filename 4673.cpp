#include <bits/stdc++.h>
using namespace std;

bool num[10001];

int cal(int x){
    string tmp = to_string(x);
    int sum = x;
    for(int i=0;i<tmp.size();i++){
        sum += (tmp[i]-'0');
    }
    return sum;
}

void d(int x){
    if(x >= 10000) return;
    num[x] = 1;
    d(cal(x));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int i=1;i<10000;i++){
        if(!num[i]) d(cal(i));
    }
    for(int i=1;i<10000;i++){
        if(!num[i]) cout << i << '\n';
    }
}