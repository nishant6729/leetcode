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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode* ans=head->next;

        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt;
        if(curr->next) nxt=curr->next;
        while(curr){
            curr->next=prev;
            if(nxt && nxt->next) prev->next=nxt->next;
            else prev->next=nxt;
            prev=nxt;
            if(prev) curr=prev->next;
            else break;
            if(!curr) break;
            nxt=curr->next;

        }
    
        return ans;
    }
};