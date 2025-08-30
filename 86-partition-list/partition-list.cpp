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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo=new ListNode(0);
        ListNode* hi=new ListNode(0);
        ListNode* tl=lo;
        ListNode* th=hi;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                tl->next=temp;
                temp=temp->next;
                tl=tl->next;
            }
            else{
                th->next=temp;
                temp=temp->next;
                th=th->next;
            }
        } 
        tl->next=hi->next;
        th->next=NULL;
        return lo->next;
    }
};