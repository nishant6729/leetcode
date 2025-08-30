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
        if(!head) return head;
        if(head->next==NULL) return head;
        ListNode* dummy=new ListNode(-101);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        while(nxt){
            bool flag=false;
            while((nxt) && curr->val == nxt->val){
                nxt=nxt->next;
                flag=true;
            }
            if(flag){
                prev->next=nxt;
                curr=nxt;
                if(nxt) nxt=nxt->next;
            }
            else{
                prev=curr;
                curr=nxt;
                nxt=nxt->next;
            }
        }
        return dummy->next;
    }
};