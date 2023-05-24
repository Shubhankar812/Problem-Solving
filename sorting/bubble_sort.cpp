#include <bits/stdc++.h>
using namespace std;

void bubble(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap(arr[j], arr[j + 1]);
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void optimized_bubble(int arr[], int n)
{
    int count = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        bool didSwap = false;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                didSwap = true;
            }
        }
        if (!didSwap)
        {
            break;
        }
        count += 1;
        cout << "ran from this point for " << count << " number of times !"
             << "\n";
    }
}
int main()
{
    int arr[6] = {13, 46, 24, 52, 20, 9};
    int n = 6;

    // bubble(arr, n);
    optimized_bubble(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}