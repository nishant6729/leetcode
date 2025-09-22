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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        if(!head || !head->next) return head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        while(nxt){
            while(nxt && curr->val==nxt->val){
                nxt=nxt->next;
            }
            if(curr->next==nxt){
                prev=curr;
                curr=nxt;
                if(curr) nxt=nxt->next;
            }
            else{
                prev->next=nxt;
                curr=nxt;
                if(curr) nxt=nxt->next;
            }
        }
        return dummy->next;
    }
};