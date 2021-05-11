class Solution {
public:
    //qsort -> 双指针
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> nums2(nums);
		int l = 0, r = nums2.size()-1;
		qsort(nums2, l, r);
		
		while(1) {
			if(nums2[l] + nums2[r] > target) r--;
			else if(nums2[l] + nums2[r] < target) l++;
			else break;
		}
		
		vector<int> res;
		
		for(int i=0;i<nums2.size();++i) {
			if((nums[i] == nums2[l]) || (nums[i] == nums2[r])) res.push_back(i);
		}
		return res;
	}

    void qsort(vector<int>& nums, int left, int right) {
        if(left < right) {
			int l = left;
			int r = right;
            int temp = nums[l];
			
			while(l<r) {
				while(l < r && nums[r] >= temp) {
					r--;
				}
				nums[l] = nums[r];
				while(l < r && nums[l] <= temp) {
					l++;
				}
				nums[r] = nums[l];
			}
			
			nums[l] = temp;
			qsort(nums, left, l-1);
			qsort(nums, l+1, right);
        }
    }
};