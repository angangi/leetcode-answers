/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        for (int i = 0; i < height.length-1; i++) {
            for (int j = i+1; j < height.length; j++) {
                int area = (j-i) * Math.min(height[i],height[j]);
                result = Math.max(result, area);
            }
        }
        return result;
    }
}
// @lc code=end

