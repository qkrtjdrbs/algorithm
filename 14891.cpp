#include <bits/stdc++.h>
using namespace std;
int k, score;
string wheel[5]; //인덱스 0 : 12시, 인덱스 1 : 1시, ...

void cal(){
    char x = '1';
    if(wheel[1][0] == x) score++;
    if(wheel[2][0] == x) score += 2;
    if(wheel[3][0] == x) score += 4;
    if(wheel[4][0] == x) score += 8;
    cout << score;
}

vector<pair<int, int>> canRollWheels(int n, int d){
    vector<pair<int, int>> v;
    int idx = n; 
    int dir = d;
    while (1){
        if(idx == 4) break;
        idx++;
        dir *= -1;
        if(wheel[idx-1][2]!=wheel[idx][6]){
            v.push_back({idx, dir});
        } else break;
    }
    idx = n; 
    dir = d;
    while (1){
        if(idx == 1) break;
        idx--;
        dir *= -1;
        if(wheel[idx+1][6]!=wheel[idx][2]){
            v.push_back({idx, dir});
        } else break;
    }
    return v;
}

void roll(int n, int d){
    vector<pair<int, int>> v = canRollWheels(n, d);
    v.push_back({n, d});
    while (!v.empty())
    {
        int newNum, newD;
        tie(newNum, newD) = v.back();
        v.pop_back();
        string tmp = wheel[newNum];
        if (newD == 1)
        { //시계
            wheel[newNum][0] = tmp[7];
            for (int i = 1; i < 8; i++)
            {
                wheel[newNum][i] = tmp[i - 1];
            }
        }
        else
        {
            wheel[newNum][7] = tmp[0];
            for (int i = 0; i < 7; i++)
            {
                wheel[newNum][i] = tmp[i + 1];
            }
        }
    }
}

int main(){
    for(int i=1;i<=4;i++){
        cin >> wheel[i];
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int n, dir;
        cin >> n >> dir;
        roll(n, dir);
    }
    cal();
}