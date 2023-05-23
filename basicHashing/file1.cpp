#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre computation
    int hsh[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hsh[arr[i]] += 1;
    }

    
    int m;
    cin >> m;

    while (m--)
    {
        int num;
        cin >> num;
        // fetching
        cout << hsh[num] << "\n";
    }
    return 0;
}