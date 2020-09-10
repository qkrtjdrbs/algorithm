#include <iostream>
using namespace std;
int E,S,M,year;

int main(){
    cin >> E >> S >> M;
    int e=1,s=1,m=1;
    for(year=1;;year++){
        if(E==e && S==s && M==m){
            cout << year;
            break;
        }
        ++e; ++s; ++m;
        if(e==16)
            e=1;
        if(s==29)
            s=1;
        if(m==20)
            m=1;            
    }
}