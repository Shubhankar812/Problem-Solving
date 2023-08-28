#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, const int &k)
{
    int i = 0, j = 0;
    int n = arr.size();
    int mx = INT_MIN;
    int sum = 0;

    while (j < n)
    {
        sum += arr[j];

        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
                if (sum == k)
                {
                    mx = max(mx, j - i + 1);
                }
            }
            j++;
        }
    }
    return mx;
}
int main()
{
    vector<int> arr = {4, 1, 1, 1, 2, 3, 5};
    int k = 5;

    int r = solve(arr, k);

    cout << r << endl;
}