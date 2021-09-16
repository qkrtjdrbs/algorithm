#include <iostream>
#include <algorithm>
using namespace std;
int N, M, b, ans;
bool broken[10];
int possible(int ch)
{
    if (ch == 0)
    {
        if (broken[0])
            return 0;
        else
            return 1;
    }
    int len = 0;
    while (ch > 0)
    {
        if (broken[ch % 10])
            return 0;
        len += 1;
        ch /= 10;
    }
    return len;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> b;
        broken[b] = true;
    }
    ans = N - 100;
    if (ans < 0)
        ans = -ans;
    for (int i = 0; i <= 1000000; i++)
    {
        int ch = i;
        if (!possible(ch))
            continue;
        else
        {
            int len = possible(ch);
            ch = ch - N;
            if (ch < 0)
                ch = -ch;
            ans = min(ans, len + ch);
        }
    }
    cout << ans;
}