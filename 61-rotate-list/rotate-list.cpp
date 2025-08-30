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
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        if(head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=curr->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(!curr) break;
            nxt=nxt->next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int s=0;
        ListNode* u=head;
        while(u){
            s++;
            u=u->next;
        }
        k=k%s;
        if(k==0) return head;
        ListNode* tail=reverse(head);
        ListNode* dummy= new ListNode(0);
        dummy->next=tail;
        ListNode* temp=dummy;
        while(k-- && temp){
            temp=temp->next;
        }
        

        ListNode* secondEnd=NULL;
        if(temp) secondEnd=temp->next;
        if(temp) temp->next=NULL;
        

        ListNode* firstStart=reverse(dummy->next);
        ListNode* secondStart=reverse(secondEnd);
        ListNode* t=firstStart;
        while(t && t->next){
            t=t->next;
        }
        if(t) t->next=secondStart;
        return firstStart;
    }
};