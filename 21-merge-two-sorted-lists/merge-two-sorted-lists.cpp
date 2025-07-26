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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
         if (list2->val < list1->val) {
            std::swap(list1, list2);
        }
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* prev1=list1;
        ListNode* prev2=list2;
        
        while (t1 && t2){
            if (t2->val>=t1->val){
                prev1=t1;
                t1=t1->next;
            }
            else{
                prev1->next=t2;
                prev2=t2;
                t2=t2->next;
                prev2->next=t1;
                 prev1=prev2;
               
            }
        }
        if (t2) {
            prev1->next = t2;
        }
        return list1;
    }
};