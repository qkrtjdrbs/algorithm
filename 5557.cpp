#include <bits/stdc++.h>
using namespace std;
int n, num[101];
long long d[101][21];

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> num[i];
    d[0][num[0]] = 1;
    for(int i=1;i<n-1;i++){
        for(int j=0;j<21;j++){
            if(j >= num[i])
                d[i][j] += d[i-1][j-num[i]];
            if(j + num[i] <= 20)    
                d[i][j] += d[i-1][j+num[i]]; 
        }
    }
    cout << d[n-2][num[n-1]];
}