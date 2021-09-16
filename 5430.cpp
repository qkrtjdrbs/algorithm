#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        string p, arr;
        deque<int> a;
        deque<int> tmp;
        int n;
        cin >> p >> n >> arr;
        for(char x : arr){
            if(x != '[' && x != ',' && x != ']'){
                tmp.push_back(x - '0');
            }
            if(x == ',' || x == ']'){
                int res = 0;
                if(tmp.empty()) break;
                while(!tmp.empty()){
                    res += tmp.front() * pow(10, tmp.size()-1);
                    tmp.pop_front();
                }
                a.push_back(res);
            }
        }
        int reverse = 1;
        int end = 0;
        int pLen = p.size();
        for(int i=0;i<pLen;i++){
            if(p[i] == 'R'){
                reverse *= -1;
            } else{
                if(a.empty()) {cout << "error" << '\n'; end = 1; break;}
                if(reverse == -1){
                    a.pop_back();
                } else{
                    a.pop_front();
                }
            }
        }
        if(end) continue;
        cout << '[';
        if(reverse == -1){
           while(!a.empty()){
               cout << a.back();
               a.pop_back();
               if(a.size()) cout << ',';
           }
        } else{
            while(!a.empty()){
               cout << a.front();
               a.pop_front();
               if(a.size()) cout << ',';
           } 
        }
        cout << ']';
        cout << '\n';
    }
}