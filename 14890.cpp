#include <bits/stdc++.h>
using namespace std;
int n, l, Map[101][101], Visit[101][101], ans;
bool checkDownBridge(int x, int y){
    if(Map[x][y] > Map[x+1][y]){
        if(l == 1 && Visit[x+1][y] == 0){
            Visit[x+1][y] = 1;
            return true;
        }
        for(int i=2;i<=l;i++){
            if((Map[x+i][y] != Map[x+i-1][y]) || (Visit[x+i][y] != 0)){
                return false;
            }
        }
        for(int i=1;i<=l;i++){
            Visit[x+i][y] = 1;
        }
        return true;
    } else {
        if(l == 1){
            if(Visit[x][y] == 0){
                Visit[x][y] = 1;
                return true;
            } else {
                return false;
            }
        }
        for(int i=1;i<l;i++){
            if((Map[x-i][y] != Map[x-i+1][y]) || (Visit[x-i][y] != 0)){
                return false;
            }
        }
        for(int i=0;i<l;i++){
            Visit[x-i][y] = 1;
        }
        return true;
    }
}
bool checkRightBridge(int x, int y){
    if(Map[x][y] > Map[x][y+1]){
        if(l == 1){
            if(Visit[x][y+1] == 0){
                Visit[x][y+1] = 1;
                return true;
            } else {
                return false;
            }
        }
        for(int i=2;i<=l;i++){
            if((Map[x][y+i] != Map[x][y+i-1]) || (Visit[x][y+i] != 0)){
                return false;
            }
        }
        for(int i=1;i<=l;i++){
            Visit[x][y+i] = 1;
        }
        return true;
    } else {
        if(l == 1){
            if(Visit[x][y] == 0){
                Visit[x][y] = 1;
                return true;
            } else {
                return false;
            }
        }
        for(int i=1;i<l;i++){
            if((Map[x][y-i] != Map[x][y-i+1]) || (Visit[x][y-i] != 0)){
                return false;
            }
        }
        for(int i=0;i<l;i++){
            Visit[x][y-i] = 1;
        }
        return true;
    }
}
void goDown(int x, int y){
    if(x == n-1){
        ++ans;
        return;
    }
    int diff = abs(Map[x][y] - Map[x+1][y]);
    if(diff == 0){
        goDown(x+1, y);
    } else if(diff == 1){
        bool cangoDown = checkDownBridge(x, y);
        if(cangoDown){
            goDown(x+1, y);
        } else {
            return;
        }
    } else return;
}
void goRight(int x, int y){
    if(y == n-1){
        ++ans;
        return;
    }
    int diff = abs(Map[x][y] - Map[x][y+1]);
    if(diff == 0){
        goRight(x, y+1);
    } else if(diff == 1){    
        bool cangoRight = checkRightBridge(x, y);
        if(cangoRight){
            goRight(x, y+1);
        } else {
            return;
        }
    } else return;
}

int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    for(int i=0;i<n;i++){
        goRight(i, 0);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Visit[i][j] = 0;
    for(int i=0;i<n;i++){
        goDown(0, i);
    }
    cout << ans;
}