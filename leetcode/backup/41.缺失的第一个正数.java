import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode.cn id=41 lang=java
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
// @lc code=start
class Solution {
    public int firstMissingPositive(int[] nums) {
        //把1，2，3，4……放到对应的0，1，2，3……
        for (int i = 0; i < nums.length; i++) {
            while(nums[i] > 0 && nums[i] <= nums.length && nums[i] != i+1
                && nums[i] != nums[nums[i]-1]) {
                //swap nums[i], nums[nums[i]-1]
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        //全是负数，第一个就不满足条件，那么返回1
        //到这里，数字全部满足要求
        return nums.length + 1;
    }
}

// @lc code=end

