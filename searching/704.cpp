#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rbs(vector<int>& nums, int tgt,int low,int high) {
        int n = nums.size();

        // base condition
        if(low > high) {
            return -1;
        }
        int mid = low + (high - low)/2;

        if(nums[mid] == tgt) {
            return mid;
        }
        else if(nums[mid] > tgt) {
            return rbs(nums,tgt,low,mid-1);
        }
        else{
            return rbs(nums,tgt,mid+1,high); 
        }
             
    }
public:
    int search(vector<int>& nums, int target) {
        
        return rbs(nums,target,0,nums.size()-1);
    }
};
int main()
{
    Solution s;
    vector<int> nums= {-1,0,3,5,9,12};
    int k = 9;
    int res = s.search(nums,k);
    cout<<res<<endl;
}