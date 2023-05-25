#include <bits/stdc++.h>
using namespace std;
vector<int> temp;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int leftSize = mid - low;
    int rightSize = high - mid + 1;
    ;

    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
        k++;
    }
    while (i < leftSize)
    {
        temp.push_back(arr[i]);
        i++;
        k++;
    }

    while (j < rightSize)
    {
        temp.push_back(arr[i]);
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high) return;
    
    int mid = (low + high) / 2;

    mergeSort(arr, low, mid - 1);
    mergeSort(arr, mid, high);
    merge(arr, low, mid, high);
}
int main()
{
    vector<int> arr = {2, 4, 1, 6, 3, 7, 8, 5};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}