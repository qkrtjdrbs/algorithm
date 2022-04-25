#include <bits/stdc++.h>
using namespace std;

string str;
int x, y;
bool visited[10], flag;

bool isRight(int a, int b){
    return a + b == stoi(str);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> str;
    if(str.size() > 6 || str.size() < 5){
        cout << "No Answer";
    } else {
        int num[10] = {0,1,2,3,4,5,6,7,8,9};
        do{
            if(!num[0] || !num[4]) continue;

            int a = 10000*num[0]+1000*num[1]
            +100*num[2]+10*num[2]+num[3];

            int b = 10000*num[4]+1000*num[3]
            +100*num[5]+10*num[2]+num[6];

            if(isRight(a, b)){
                flag = true;
                x = a; y = b;
                break;
            }
        }while(next_permutation(num, num+10));

        if(flag){
            cout << "  " << x << '\n';
            cout << "+ " << y << '\n';
            cout << "-------\n";
            for(int i=0;i<7-str.size();i++) cout << ' ';
            cout << str << '\n';
        } else {
            cout << "No Answer";
        }
    }
}