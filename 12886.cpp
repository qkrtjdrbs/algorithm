#include <iostream>
using namespace std;
int a,b,c,sum=0;
bool check[1501][1501];
void go(int x, int y){
    if(check[x][y]) return;
    check[x][y]=true;
    int z=sum-x-y;
    if(x < y){
        go(x+x,y-x);
    }
    if(x < z){
        go(x+x,z-x);
    }
    if(y < x){
        go(y+y,x-y);
    }
    if(y < z){
        go(y+y,z-y);
    }
    if(z < x){
        go(z+z,x-z);
    }
    if(z < y){
        go(z+z,y-z);
    }
}
int main(){
    cin >> a >> b >> c;
    sum=a+b+c;
    if((sum%3)!=0){
        cout << 0;
        return 0;
    }
    go(a,b);
    if(check[sum/3][sum/3]){
        cout << 1;
    } else {
        cout << 0;
    }
}