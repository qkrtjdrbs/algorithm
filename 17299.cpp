#include <iostream>
#include <stack>
using namespace std;
int n,a[1000001],ngf[1000001],f[1000001];

int main(){
    stack<int> s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        while(!s.empty() && f[a[s.top()]]<f[a[i]]){
            ngf[s.top()]=a[i];
            s.pop();
        }
        s.push(i); //오큰수 아직 못찾았을 경우
    }
    while(!s.empty()){
        ngf[s.top()]=-1;
        s.pop();
    }
    for(int i=1;i<=n;i++)
        cout << ngf[i] << ' ';
}