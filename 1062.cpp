#include <iostream>
#include <algorithm>
using namespace std;
int n, k, words[50], ans=0;
string s;
int count(int mask)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if ((words[i] & ((1 << 26) - 1 - mask)) == 0)
        {
            cnt += 1;
        }
    }
    return cnt;
}
int go(int index, int _k, int mask)
{
    if (_k < 0)
        return 0;
    if (index == 26)
        return count(mask);
    int t1 = go(index + 1, _k - 1, mask | (1 << index));
    ans = max(ans, t1);
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
    {
        t1 = go(index + 1, _k, mask);
        ans = max(ans, t1);
    }
    return ans;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (char x : s)
        {
            words[i] |= (1 << (x - 'a'));
        }
    }
    cout << go(0, k, 0);
}