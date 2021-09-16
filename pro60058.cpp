#include <bits/stdc++.h>
using namespace std;

string go(string p)
{
    string u = "", v = "";
    stack<char> s;
    int pLen = p.size();
    bool good = true;
    for (auto x : p)
    {
        if (x == '(')
            s.push(x);
        //올바르지 않음
        else
        {
            good = false;
            if (s.empty())
            {
                int o = 0, c = 0, uGood = false;
                string tmp;
                for (int i = 0; i < pLen; i++)
                {
                    if (p[i] == '(')
                        o++;
                    else
                        c++;
                    tmp += p[i];
                    //균형 잡힘
                    if (o != 0 && c != 0 && o == c)
                    {
                        uGood = true;
                        u = tmp;
                        v = p.substr(tmp.size(), p.size() - tmp.size());
                        break;
                    }
                }
                //균형 안 잡힘
                if (!uGood)
                {
                    string emp = "", t = "";
                    emp += "(";
                    emp += go(v);
                    emp += ")";
                    u = u.substr(1, u.size() - 1);
                    for (auto x : u)
                    {
                        if (x == '(')
                            t += ")";
                        else
                            t += "(";
                    }
                    emp += u;
                    return emp;
                    //균형 잡힘
                }
                else
                {
                    stack<char> t;
                    bool ok = true;
                    for (auto z : u)
                    {
                        if (z == '(')
                            t.push(z);
                        else
                        {
                            if (t.empty())
                            {
                                ok = false;
                                break;
                            }
                            t.pop();
                        }
                    }
                    if (!ok)
                    {
                        string emp = "", t = "";
                        emp += "(";
                        emp += go(v);
                        emp += ")";
                        u = u.substr(1, u.size() - 1);
                        for (auto x : u)
                        {
                            if (x == '(')
                                t += ")";
                            else
                                t += "(";
                        }
                        emp += u;
                        return emp;
                    }
                    else
                    {
                        u += go(v);
                    }
                }
            }
            else
            {
                s.pop();
            }
        }
    }
    if (good)
    {
        return p;
    }
    return u;
}

string solution(string p)
{
    string ans = "", u = "", v = "";
    int pLen = p.size();
    if (pLen == 0)
        return ans;

    ans = go(p);

    return ans;
}

int main()
{
    cout << solution("(()())()");
}