import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=229 lang=java
 * 用map当然可以，但是复杂度太高
 * O(n)的话，考虑用摩尔选举法，首先定义两个被选举位置，然后
 * 遍历数组，如果属于两个位置中的一个，那么就+1，如果其中一
 * 个为0，那么就占位并设为1，否则就把两个位置的数字都-1（相
 * 当于一换一，但是把1v1的摩尔选举法推广到最多两个赢家，这
 * 两个赢家分为几种情况：两个都大于ceil(n/3)，那么剩下的所
 * 有数字都打不赢这两个，或者只有一个大于ceil(n/3)，这时候
 * 由于1换2的机制，仍然）
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        if(nums.length == 1) {
            result.add(nums[0]);
            return result;
        };

        int res0, res1;
        int cnt0=0, cnt1=0;
        res0 = nums[0];
        res1 = nums[1];

        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == res0) cnt0++;
            else if(nums[i] == res1) cnt1++;
            else if(cnt0==0) {
                res0 = nums[i];
                cnt0 = 1;
            } else if(cnt1==0) {
                res1 = nums[i];
                cnt1 = 1;
            } else {
                cnt0--;
                cnt1--;
            }
        }

        cnt0=cnt1=0;
        for (int i=0;i<nums.length;++i){
            if(nums[i] == res0) cnt0++;
            else if(nums[i] == res1) cnt1++;
        }

        if(cnt0 > nums.length / 3) result.add(res0);
        if(cnt1 > nums.length / 3) result.add(res1);

        return result;
        
    }
}
// @lc code=end

