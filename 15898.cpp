#include <bits/stdc++.h>
using namespace std;

int n, ans, effect[11][5][5][4];
int dx[] = {0,0,1,1};
int dy[] = {0,1,0,1};
char element[11][5][5][4];
bool selected[11];
vector<int> elements, starting, rotating;

char resElement(char x, char y){
    if(x == 'W') return y;
    if(y == 'W') return x;
    return y;
}

int resEffect(int x, int y){
    if(x + y > 9) return 9;
    if(x + y < 0) return 0;
    return x + y;
}


void putElement(){
    vector<int> orders = {0, 1, 2};
    int tef[5][5]; char tel[5][5];
    memset(tef, 0, sizeof(tef));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) tel[i][j] = 'W';
    }
    do{
        for(int idx=0;idx<3;idx++){
            int sx = dx[starting[idx]];
            int sy = dy[starting[idx]];
            int order = orders[idx];
            for(int i=sx;i<sx+4;i++){
                for(int j=sy;j<sy+4;j++){
                    tef[i][j] = resEffect(tef[i][j], effect[elements[order]][i-sx][j-sy][rotating[idx]]);
                    tel[i][j] = resElement(tel[i][j], element[elements[order]][i-sx][j-sy][rotating[idx]]);
                }
            }
        }
        int r=0, b=0, g=0, y=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(tel[i][j] == 'R') r += tef[i][j];
                else if(tel[i][j] == 'B') b += tef[i][j];
                else if(tel[i][j] == 'G') g += tef[i][j];
                else if(tel[i][j] == 'Y') y += tef[i][j];
            }
        }
        ans = max(ans, 7*r+5*b+3*g+2*y);
        memset(tef, 0, sizeof(tef));
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++) tel[i][j] = 'W';
        }
    }while(next_permutation(orders.begin(), orders.end()));
}

void selectRotate(int cnt){
    if(cnt == 3){
        putElement();
        return;
    }
    for(int i=0;i<4;i++){
        rotating.push_back(i);
        selectRotate(cnt+1);
        rotating.pop_back();
    }
}


void selectStart(int cnt){
    if(cnt == 3){
        selectRotate(0);
        return;
    }
    for(int i=0;i<4;i++){
        starting.push_back(i);
        selectStart(cnt+1);
        starting.pop_back();
    }
}

void selectElements(int idx, int cnt){
    if(cnt == 3){
        selectStart(0);
        return;
    }
    for(int i=idx;i<n;i++){
        if(!selected[i]){
            selected[i] = 1;
            elements.push_back(i);
            selectElements(i+1, cnt+1);
            elements.pop_back();
            selected[i] = 0;
        }
    }
}

void rotate(int idx){
    int tef[4][4]; char tel[4][4];
    for(int k=1;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                tef[j][3-i] = effect[idx][i][j][k-1];
                tel[j][3-i] = element[idx][i][j][k-1];
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                effect[idx][i][j][k] = tef[i][j];
                element[idx][i][j][k] = tel[i][j];
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int k=0;k<n;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) cin >> effect[k][i][j][0];
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) cin >> element[k][i][j][0];
        }
    }
    for(int i=0;i<n;i++) rotate(i);
    selectElements(0, 0);
    cout << ans;
}