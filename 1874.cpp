#include <iostream>
#include <stack>
using namespace std;
int n,m=0;

int main(){
    cin >> n;
    string ans;
    stack<int> st;
    
    while(n--){
        int x;
        cin >> x;
        if(x>m){
            while(x>m){
                st.push(++m);
                ans+='+';
            }
            st.pop();
            ans+='-';
        }
        else{
            bool found=false;
            if(!st.empty()){
                int top=st.top();
                st.pop();
                ans+='-';
                if(top==x){
                    found=true;
                }
            }
            if(found==false){
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    for(auto w : ans){
        cout << w << '\n';
    }
}