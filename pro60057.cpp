#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = 1000, len = s.size();
    for (int cut = 1; cut <= len / 2; cut++)
    {
        vector<string> a;
        for (int i = 0; i < len; i += cut)
        {
            string t = s.substr(i, cut);
            a.push_back(t);
        }

        int aLen = a.size(), cnt = 1;
        string tmp = a[0];
        for (int i = 1; i < aLen; i++)
        {
            if (a[i] != a[i - 1])
            {
                if (cnt <= 1)
                    tmp += a[i];
                else
                {
                    tmp += to_string(cnt);
                    tmp += a[i - 1];
                }
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        cout << tmp << '\n';
        int res = tmp.size();
        answer = min(answer, res);
    }
    return answer;
}

int main(){
    cout << solution("aabbaccc");
}