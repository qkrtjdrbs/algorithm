#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> A,B;
int m;
char input;
string s;

int main(){
    cin >> s;
    for(int i=0;i<s.size();i++){
        A.push(s[i]);
    } 
    cin >> m;
    while(m--){
        cin >> input;
        if(input=='L'){
            if(!A.empty()){
                B.push(A.top());
                A.pop();
            }
        }
        else if(input=='D'){
            if(!B.empty()){
                A.push(B.top());
                B.pop();
            }
        }
        else if(input=='B'){
            if(!A.empty())
                A.pop();
        }
        else if(input=='P'){
            char add;
            scanf(" %c",&add);
            A.push(add);
        }
    }
    while(!A.empty()){
        B.push(A.top());
        A.pop();
    }
    while(!B.empty()){
        cout << B.top();
        B.pop();
    }
}