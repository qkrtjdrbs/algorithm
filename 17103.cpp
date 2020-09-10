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
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int sum=0;
        for(int i=2;i+i<=n;i++){
            if(check[i]==false && check[n-i]==false){
                sum+=1;
            }
        }
        cout << sum << '\n';
    }
}