#include <bits/stdc++.h>
using namespace std;

int count(string &s, string &p)
{
    int k = p.length();
    int n = s.length();

    int i = 0, j = 0;
    int ans = 0;

    vector<int> pattern(26, 0);
    for (int i = 0; i < k; i++)
    {
        pattern[p[i] - 'a']++;
    }
    vector<int> txt(26, 0);

    while (j < n)
    {
        txt[s[j] - 'a']++;

        if (j - i + 1 == k)
        {
            if (txt == pattern)
            {
                ans++;
            }
            txt[s[i]-'a']--;
            i++;
        }
        j++;
    }
    return ans;
}
int main()
{
    string s = "aabaabaa";
    string p = "aaba";

    int res = count(s, p);

    cout << res << "\n";
}