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
    ListNode* bahar;
    ListNode* reverse(ListNode* root){
        ListNode* prev=NULL;
        ListNode* curr=root;
        ListNode* nxt;
        if(curr) nxt=curr->next;
        else nxt=NULL;
        
        while(curr!=bahar){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt) nxt=nxt->next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* start=dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++){
            start=start->next;
        }
        ListNode* end=dummy;
        
        for(int i=0;i<=right;i++){
            if(end) end=end->next;
        }
        bahar=end;
        ListNode* second=start->next;
        if(start) start->next=reverse(second);
        ListNode* temp=start;

        while(temp && temp->next){
            temp=temp->next;
        }
        if(temp) temp->next=end;
        return dummy->next;
    }
};