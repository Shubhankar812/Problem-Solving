#include <bits/stdc++.h>
using namespace std;

vector<int> first(vector<int> &nums,int k) {
    vector<int> ans;
    int i=0,j=0;

    while(j<nums.size()) {
        if(j-i+1 < k) {
            j++;
        }
        else if(j-i+1 == k) {
            for(int l=i;l<j;l++) {
                if(nums[l] < 0) {
                    ans.push_back(nums[l]);
                    break;
                }
            }
        
        j++;
        i++;
    }
    }
       return ans;
}
int main() {
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    vector<int> res = first(arr,3);

    for(auto x : res) {
        cout<<x<<" ";
    }
    cout<<endl;
}