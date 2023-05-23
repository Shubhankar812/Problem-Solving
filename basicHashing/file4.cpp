#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // pre-computation
    map<char, int> mpp;

    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        char c;
        cin >> c;

        // fetching
        cout << mpp[c-'a'] << " ";
    }
    cout << endl;
}