#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int k;
string _min= "9876543210", _max="0";
bool check[10];
char sign[12];
bool check2(char x, char y, char op) {
    if (op == '<') {
        if (x > y) return false;
    }
    if (op == '>') {
        if (x < y) return false;
    }
    return true;
}
void go(string s, int index){
    if(index==k+1){
        _min=min(_min, s);
        _max=max(_max, s);
    }
    for(int i=0;i<=9;i++){
        if(check[i]) continue;
        if(index==0 || check2(s[index-1],i+'0',sign[index-1])){
            check[i]=true;
            char tmp=i+'0';
            go(s+tmp,index+1);
            check[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k;
    for(int i=0;i<k;i++)
        cin >> sign[i];
    go("",0);
    cout << _max << '\n' << _min;
}