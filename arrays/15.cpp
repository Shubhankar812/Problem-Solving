class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++) {
            int low=i+1, high=n-1;
            while(low < high) {

                if(nums[i]+nums[low]+nums[high] < 0) {
                   low++;
                }
                else if(nums[i]+nums[low]+nums[high] > 0) {
                   high--;
                }
                else if(nums[i]+nums[low]+nums[high] == 0){
                  st.insert({nums[i],nums[low],nums[high]});
                  low++;
                  high--;
                }
            }
        }
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};