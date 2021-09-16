#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, exp, ans = "";
    cin >> s >> exp;
    int idx = 0;
    int sLen = s.length();
    int expLen = exp.length();
    for (int i = 0; i < sLen; i++)
    {
        ans += s[i];
        if (s[i] == exp[expLen - 1])
        {
            bool check = true;
            for (int j = 0; j < expLen; j++)
            {
                if (ans[ans.length() - 1 - j] != exp[expLen - 1 - j])
                {
                    check = false;
                    break;
                }
                idx = ans.length() - 1 - j;
            }
            if (check)
            {
                for (int k = 0; k < expLen; k++)
                {
                    ans.pop_back();
                }
            }
        }
    }
    ans.empty() ? ans = "FRULA" : ans;
    cout << ans;
}