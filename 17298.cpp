#include <iostream>
#include <stack>
using namespace std;
int n,a[1000001],nge[1000001];

int main(){
    stack<int> s;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            nge[s.top()]=a[i];
            s.pop();
        }
        s.push(i); //��ū�� ���� ��ã���� ���
    }
    while(!s.empty()){
        nge[s.top()]=-1;
        s.pop();
    }
    for(int i=1;i<=n;i++)
        cout << nge[i] << ' ';
}