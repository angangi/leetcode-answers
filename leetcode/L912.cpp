class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums;
        }
        //arr 第一个 最后一个元素
        qsort(nums, 0, nums.size()-1);
        return nums;
    }
    void qsort(vector<int>& nums, int left, int right) {

        if(left < right) {
            int l = left, r = right;

            //交换位置,避免n^2情况，当然有一定的概率
            int t = nums[(l + r)/2];
            nums[(l + r)/2] = nums[l];
            nums[l] = t;

            int temp = nums[l];
            while(l < r) {
                
                while(l < r && nums[r] >= temp) {
                    r--;
                }
                nums[l] = nums[r];
                while(l < r && nums[l] <= temp) {
                    l++;
                }
                nums[r] = nums[l];
            }

            //注意填充谁
            nums[l] = temp;
            qsort(nums, left, l-1);
            qsort(nums, l+1,right);
        }
    }
};