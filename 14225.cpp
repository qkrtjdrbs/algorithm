#include <iostream>
using namespace std;
int n,s[21];
bool check[20*100000+1];
void go(int index, int sum){
    if(index==n){
        check[sum]=true;
        return;
    }
    go(index+1, sum+s[index]);
    go(index+1, sum);
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    go(0,0);
    for(int i=1;i<20*100000+1;i++){
        if(!check[i]){
            cout << i;
            return 0; 
        }
    }
}