#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int> &arr,int left,int right) {

    if(left>=right) {
        return;
    }
    int t = arr[left];
    arr[left] = arr[right];
    arr[right] = t;

    Reverse(arr,left+1,right-1);

}
void display(vector<int> arr) {
    for(auto it : arr) {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    Reverse(arr,0,n-1);
    display(arr);
}