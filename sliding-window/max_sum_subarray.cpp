#include <bits/stdc++.h>
using namespace std;

int MaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0, mx = INT_MIN;

    while (j < n)
    {
        sum += arr[j];

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            mx = max(mx, sum);
            sum-=arr[i];
            i++;
            j++;
        }
    }
    return mx;
}
int main()
{
    vector<int> arr = {2,3,5,2,9,7,1};
    int k=3;

    cout<<MaxSum(arr,k)<<endl;
    
}