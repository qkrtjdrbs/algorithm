#include <iostream>
using namespace std;
int n,s,a[21],ans=0;

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<(1 << n);i++){
        int sum=0;
        for(int k=0;k<i;k++){
            if(i&(1 << k)){
                sum+=a[k];
            }
        }
        if(sum==s)
            ans+=1;
    }
    cout << ans;   
}