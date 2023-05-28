class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        int result = nums[0]+nums[1]+nums[n-1];

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++) {
            int low=i+1, high=n-1;

            while(low < high) {
                int current = nums[i] + nums[low]+nums[high];
                
                // for the two pointers
                if(current < target) {
                    low++;
                }
                else{
                    high--;
                }
            
            if(abs(result-target) > abs(current-target)){
                result = current;
            }
        }
        }
        return result;
    }
};