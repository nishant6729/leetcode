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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(501);
        dummy->next=head;
        ListNode* start=dummy;
        for(int i=0;i<left-1;i++){
            start=start->next;
        }
        ListNode* end=dummy;
        for(int i=0;i<right+1;i++){
           
            end=end->next;
        }
        
        ListNode* prev=end;
        ListNode* curr=start->next;
        ListNode* nxt=curr->next;
        while(curr!=end){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(!curr) break;
            nxt=nxt->next;
        }
        start->next=prev;
        return dummy->next;
    }
};