#include <iostream>
using namespace std;
int n,a[101],ans=0;
bool prime(int x){
    if(x==1) return false;
    for(int i=2;i+i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        if(prime(a[i])) ++ans;
    }
    cout << ans;
}