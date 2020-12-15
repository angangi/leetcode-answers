/*
 * @lc app=leetcode.cn id=80 lang=java
 *
 * [80] 删除排序数组中的重复项 II
 * 使用追赶法，列出三种情况分别对前后指针进行递增操作
 */

// @lc code=start
class Solution {
    private int bulk;
    public int removeDuplicates(int[] nums) {
        int put_place = 1;
        for(int start = 2;start < nums.length; ) {
            if(nums[start] != nums[put_place] ) {
                put_place++;
                nums[put_place] = nums[start];
                start++;
            } else {
                if (nums[put_place] != nums[put_place-1]) {
                    put_place++;
                    nums[put_place] = nums[start];
                    start++;
                } else  {
                    start++;
                }
            }
        }
        return put_place+1;
    }
}
// @lc code=end

