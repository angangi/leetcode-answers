class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int max = nums[0];
            vector<int> dp;
            dp.push_back(max);
            for(int i=1;i<nums.size();++i) {
                //包含这个数
                int new_val = nums[i] + dp[i-1];
                if(new_val > nums[i]) {
                    dp.push_back(new_val);
                }
                else {
                    dp.push_back(nums[i]);
                }
                if(dp[i] > max) {
                    max = dp[i];
                }
            }
            return max;
    }
};