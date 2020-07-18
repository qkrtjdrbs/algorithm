#include <iostream>
#include <stack>
using namespace std;
int t;

int main(){
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        s+='\n';
        stack<char> word;
        for(char a : s){
            if(a==' ' || a=='\n'){
                while(!word.empty()){
                    cout << word.top();
                    word.pop();
                }
                cout << a;
            }
            else{
                word.push(a);
            }
        }
    }
}