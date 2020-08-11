#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100001],ans;
int main(){
    int dl[100001], dr[100001];
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        dl[i]=a[i];
        if(a[i]+dl[i-1] > dl[i])
            dl[i]=a[i]+dl[i-1];
    }
    for(int i=n;i>=1;i--){
        dr[i]=a[i];
        if(a[i]+dr[i+1] > dr[i])
            dr[i]=a[i]+dr[i+1];
    }
    ans=dl[1];
    for(int i=2;i<=n;i++){
        if(ans < dl[i])
            ans = dl[i];
    }
    for(int i=2;i<=n-1;i++){
        ans = max(ans, dr[i+1]+dl[i-1]);
    }
    cout << ans;
}