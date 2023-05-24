#include <bits/stdc++.h>
using namespace std;

void insertion(int arr[],int n)
{
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]) {
            int tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;

            j--;
        }
    }
}
int main()
{
    int arr[6] = {13, 46, 24, 52, 20, 9};
    int n = 6;

   insertion(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}