/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //stack定义，长度为k
        stack<int> st;
        //header开始，tail=header+k-1结束，进栈k个元素，
        ListNode *header = head;
        ListNode *tail = head;
        while(head != nullptr) {
            //header开始，出栈k个元素
            int flag = k;
            while(tail != nullptr && flag > 0) {
                st.push(tail->val);
                tail = tail->next;
                flag--;
            }
            //正好k个
            if(flag == 0) {
                for(int i=0;i<k;++i) {
                    header->val = st.top();
                    st.pop();
                    header = header->next;
                }
            }
            else{
                return head;
            }
        }
        return head;
    }
};