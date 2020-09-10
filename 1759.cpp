#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int L, C;
char a[16];
bool check(string s)
{
    int za = 0, mo = 0;
    for (int i = 0; i < L; i++)
    {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u')
        {
            mo += 1;
        }
        else
            za += 1;
    }
    if (mo >= 1 && za >= 2)
    {
        return true;
    }
    else
        return false;
}
void go(string pw, int index)
{
    if (pw.length() == L && check(pw))
    {
        cout << pw << '\n';
        return;
    }
    if (index == C)
        return;
    go(pw+a[index], index+1);
    go(pw, index+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> a[i];
    sort(a, a + C);
    go("",0);
}