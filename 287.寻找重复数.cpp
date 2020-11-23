/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    //2020.11.23
    int findDuplicate(vector<int>& nums) {
        //n+1大小的数组，[1,n]之间的数字，取中值，
        //如果小于等于中值的数字个数（小于）等于中值
        //则重复数在右侧，如果大于中值则在包括中值在内的
        //左侧子数组
        /*
        忽略了某些数字不存在的情况，但是假设一个数字不存在，
        那么必须有另外一个数字重复，这样就在原本的重复一个数字
        的基础上又重复了一个数字，显然不可能，所以这个解法也是可以的
        */
        int cnt = 0;

        int left = 1;
        int right = nums.size()-1;
        int mid = (left + right) / 2;
        while(left < right)
        {
            mid = (left + right) /2;
            for(int i=0;i<nums.size();++i)
            {
                if(nums[i] <= mid)
                {
                    cnt++;
                }
            }
            if(cnt > mid)
            {
                right = mid;
            }
            else if(cnt = mid)
            {
                left = mid + 1;
            }
            cnt=0;
        }
        return left;
    }
};
// @lc code=end

