// selection sort
#include <bits/stdc++.h>
using namespace std;


void selection(int arr[], int n)
{
    int mn;
    for (int i = 0; i < n - 1; i++)
    {
        mn = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[mn] > arr[j])
            {
                mn = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[mn];
        arr[mn] = tmp;
    }
}
int main()
{
    int arr[5] = {4, 5, 8, 1, 2};
    int n = 5;

    selection(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}