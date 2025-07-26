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
    bool isPalindrome(ListNode* head) {
        ListNode *f=head, *s=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode *prev=nullptr;
        while (s){
            ListNode *n=s->next;
            s->next=prev;
            prev=s;
            s=n;
        }
        ListNode *mid=prev;
        ListNode *b=head;
        while(mid){
            if(b->val==mid->val){
                mid=mid->next;
                b=b->next;
            }
            else{
                return false;
            }
        }
        return true;

    }
};