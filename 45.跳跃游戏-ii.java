/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 * 第一个范围是首元素
 * 对范围内所有的元素进行从左到右的遍历，看能达到的最远范围，
 * 这个最远范围就是当前步数下的能力极限了，不能到最后一个元素
 * 就得继续扩展步数。
 * 然后扩展这个范围为上一步得到的最远范围，同时step+=1
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        if(nums.length == 1) return 0;
        int inControl = 0;
        int notTranversed = 0;
        int step=0;
        while(inControl < nums.length-1) {
            int max = inControl;
            for(int i = notTranversed;i<=inControl;++i) {
                max = i+nums[i] > max ? i+nums[i] : max;
                if(max >= nums.length-1) return step+1;
            }
            step++;
            notTranversed = inControl + 1;
            inControl = max;
        }
        return step;
    }
    /* TLE解法
        int res = 0;
        //当前目标ending
        int endPos = nums.length - 1;
        while(endPos != 0) {
            for(int i=0;i<endPos;++i) {
                if(endPos - i <= nums[i]) {
                    endPos = i;
                    break;
                }
            }
            res++;
        }
        return res;
    */
}
// @lc code=end

