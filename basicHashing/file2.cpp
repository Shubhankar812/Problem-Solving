#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // pre-computation
    int hsh[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hsh[s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char ch;
        cin >> ch;

        // fetching
        cout << hsh[ch - 'a']<<endl;
    }
    return 0;
}