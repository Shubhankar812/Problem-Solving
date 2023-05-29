#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int start = 0, end = 0;

    while (end < n)
    {

        if (nums[end] == 0)
        {
            k--;
        }
        if (k < 0)
        {
            if (nums[start] == 0)
            {
                k++;
            }
            start++;
        }
        end++;
    }
    return (end - start);
}
int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k=2;

    cout<<longestOnes(nums,k)<<endl;
}