/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        char arr[26];
        int max = 0;
        //对于每一个字母
        for(int i = 0;i<26;++i) {
            int min = 0;
            //对于每一个字符串
            for(int j=0;j<A.size();++j) {
                //对于字符串中的每一个字符
                for(int k=0;k<A[j].size();++k) {
                    if(A[j][k] == 'a'+i) {

                    }
                }
            }
        }
    }
};
// @lc code=end

