#include <iostream>
using namespace std;
int N;
long long ans=0;

int main(){
    cin >> N;
    for(int i=1,plus=1;i<=N;i*=10,plus++){
        if(i*10>N){
            ans+=plus*(N-i+1);
            break;
        }
        else
            ans+=i*9*plus;
    }
    cout << ans;
}
