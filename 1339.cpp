#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n,m;
char added[256];
vector<string> b(10);
vector<char> letter;
vector<int> d;
int cal(){
    int sum=0;
    for(int i=0;i<m;i++){
        added[letter[i]]=d[i];
    }
    for(string x : b){
        int now = 0;
        for(char a : x){
            now = now*10 + added[a];
        }
        sum+=now;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> b[i];
        for(char x : b[i])
            letter.push_back(x);
    }
    sort(letter.begin(), letter.end());
    letter.erase(unique(letter.begin(), letter.end()),letter.end());
    m=letter.size();
    for(int i=9;i>9-m;i--){
        d.push_back(i);
    }
    sort(d.begin(), d.end());
    int ans=0;
    do{
        int result=cal();
        ans = max(ans, result);
    }while(next_permutation(d.begin(), d.end()));
    cout << ans;
}