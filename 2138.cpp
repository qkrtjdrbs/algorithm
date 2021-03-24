#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[100001], b[100001], t[100001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%1d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%1d", &b[i]);
    for (int i = 0; i < n; i++)
        t[i] = a[i];
    //첫번째 안킨 경우
    int cnt1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] != b[i - 1])
        {
            if (i == n - 1)
            {
                a[i - 1] = 1 - a[i - 1];
                a[i] = 1 - a[i];
                cnt1 += 1;
            }
            else
            {
                a[i - 1] = 1 - a[i - 1];
                a[i] = 1 - a[i];
                a[i + 1] = 1 - a[i + 1];
                cnt1 += 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            cnt1 = -1;
        }
    for (int i = 0; i < n; i++)
        a[i] = t[i];
    //첫번째 킨 경우
    int cnt2 = 1;
    a[0] = 1 - a[0];
    a[1] = 1 - a[1];
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] != b[i - 1])
        {
            if (i == n - 1)
            {
                a[i - 1] = 1 - a[i - 1];
                a[i] = 1 - a[i];
                cnt2 += 1;
            }
            else
            {
                a[i - 1] = 1 - a[i - 1];
                a[i] = 1 - a[i];
                a[i + 1] = 1 - a[i + 1];
                cnt2 += 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            cnt2 = -1;
        }
    if (cnt1 == -1 && cnt2 == -1)
    {
        cout << -1;
        return 0;
    }
    if (cnt1 != -1 && cnt2 != -1)
        cout << min(cnt1, cnt2);
    if (cnt1 == -1)
        cout << cnt2;
    if (cnt2 == -1)
        cout << cnt1;
}