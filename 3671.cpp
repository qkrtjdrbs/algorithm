#include <bits/stdc++.h>
#include <unordered_set>
#define MAX 10000000
using namespace std;

int t;
string s;
bool notPrime[MAX+1];
unordered_set<int> st;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    notPrime[0] = 1; notPrime[1] = 1;
    for(int i=2;i<=sqrt(MAX);i++){
        if(notPrime[i]) continue;
        for(int j=i*i;j<=MAX;j+=i){
            notPrime[j] = 1;
        }
    }
    cin >> t;
    for(int i=0;i<t;i++){
        st.clear();
        cin >> s;
        sort(s.begin(), s.end());
        do{
            string res = "";
            for(int j=0;j<s.size();j++){
                res += s[j];
                st.insert(stoi(res));
            }
        }while(next_permutation(s.begin(), s.end()));
        int ans = 0;
        for(auto x : st){
            if(!notPrime[x]) ans++;
        }
        cout << ans << '\n';
    }
}