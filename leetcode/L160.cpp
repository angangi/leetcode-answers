/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *longer=headA, *shorter=headB, *tmp;
        
        ListNode *long_branch, *short_branch;
        //两个head行进速度一致，遍历其中最短的一遍到end，然后另一个到end，如果同一个end，则返回两个的差值
        while(headA->next != NULL && headB->next != NULL) {
            headA = headA -> next;
            headB = headB -> next;
        }

        if(headB->next != NULL) {
            long_branch = headB;
            short_branch = headA;
            
            tmp = longer;
            longer = shorter;
            shorter = tmp;
        } else {
            long_branch = headA;
            short_branch = headB;
        }
        
        int k = 0;
        
        while(long_branch->next!=NULL) {
            k++;
            long_branch = long_branch -> next;
        }

        if(long_branch != short_branch) {
            return NULL;
        }

        for(int i=0;i<k;++i) {
            longer = longer -> next;
        }

        while(longer != shorter) {
            longer = longer -> next;
            shorter = shorter -> next;
        }

        return longer;

    }
};