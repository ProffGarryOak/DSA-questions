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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        ListNode *t1=head;
        if (not t1){
            return t1;
        }
        while(t1->next){
            len++;
            t1=t1->next;
        }
        cout<<len;
        t1->next=head;
        k=k%len;
        len-=k;
        cout<<len;
        t1=head;
        while(len>1){
            t1=t1->next;
            len--;
        }
        cout<<t1->val;
        ListNode *ans=t1->next;
        t1->next=nullptr;
        return ans;
    }
};