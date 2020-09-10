#include <iostream>
#include <stack>
using namespace std;
int i=0;
int total=0;

int main(){
    stack<int> A;
    string s;
    cin >> s;
    for(char c : s){
        if(c=='('){
            A.push(++i);
        }
        else if(c==')'){
            ++i;
            if(i-A.top()==1){
                A.pop();
                total+=A.size();
            }
            else{
                A.pop();
                total+=1;
            }
        }
    }
    cout << total;
}