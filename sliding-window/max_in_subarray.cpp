#include <bits/stdc++.h>
using namespace std;



vector<int> MaxSubarray(vector<int> &nums, int k, int n)
{
    vector<int> output;

    int mx = INT_MIN;
    int i = 0, j = 0;
    while (j < n)
    {
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            for (int l = i; l <= j; l++)
            {
                if (mx < nums[l])
                {
                    mx = max(mx, nums[l]);
                }
            }
            output.push_back(mx);
            j++;
            i++;
        }
    }
    return output;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = nums.size();
   

    vector<int> res =  MaxSubarray(nums, k, n);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}