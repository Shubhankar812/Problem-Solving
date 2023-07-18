#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000

bool hsh[MAX + 1][2];

void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            hsh[a[i]][0] = 1;
        }
        else
        {
            hsh[abs(a[i])][1] = 1;
        }
    }
}
bool search(int key)
{
    if(key >= 0){
       if(hsh[key][0] == 1) {
        return true;
       }
       else{
        return false;
       }
    }
    else{
        key = abs(key);
        if(hsh[key][1] == 1) {
            return true;
        }
        else{
            return false;
        }
    }
}
int main()
{
    int arr[] = {1, -2, 8, 4, -5};
    int n = sizeof(arr)/sizeof(arr[0]);

    insert(arr,n);
    cout<<search(-5)<<endl;
    cout<<search(9)<<endl;
    cout<<search(8)<<endl;
}