/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        //长度小于等于1，true
        //长度大于1，从倒数第1个开始往前找能不能到此元素的元素，能
        //则判断是不是第一个元素，是则返回true，不是第一个元素，
        //递归这个过程
        return canNext(nums, nums.length-1);
    }  

    private boolean canNext(int[] nums, int idx) {
        if(idx == 0) return true;
        //往前找能到idx的元素
        for(int i=idx-1; i>=0; i--) {
            if(idx-i <= nums[i]) {
                return canNext(nums, i);
            }
        }
        //都不行
        return false;
    }
}
// @lc code=end

