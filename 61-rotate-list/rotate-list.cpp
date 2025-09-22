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
    ListNode* reverse(ListNode* head,ListNode* end){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt;
        if(curr){
            nxt=curr->next;
        }
        else nxt=NULL;
        while(curr!=end){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(curr) nxt=nxt->next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || !head->next) return head;
        ListNode* t=head;
        int size=0;
        while(t){
            t=t->next;
            size++;
        }
        
        k=k%size;
        if(k==0 || k==size) return head;
        head=reverse(head,NULL);
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        
        ListNode* end=head;
        for(int i=0;i<k;i++){
            if(end) end=end->next;
        }
        dummy->next=reverse(head,end);
        end=reverse(end,NULL);
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=end;
        return dummy->next;
    }
};