#include <iostream>
using namespace std;
bool check[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    check[0] = check[1] = true;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (check[i] == false)
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                check[j] = true;
        }
    }
    for(;;){
        cin >> n;
        bool flag=false;
        if(n==0) break;
        for(int i=2;i+i<=n;i++){
            if(check[i]==false && check[n-i]==false){
                cout << n << " = " << i << " + " << n-i << '\n';
                flag=true;
                break;
            }
        }
        if(!flag) cout << "Goldbach's conjecture is wrong." << '\n';
    }
}