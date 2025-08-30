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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s=0;
        ListNode* tail=head;
        while(tail){
            s++;
            tail=tail->next;
        }
        if(s==1){
            if(n==1) return NULL;
            else return head;
        }
        if(s==n) return head->next;
        ListNode*temp=head;
        cout<<s;
        int req=s-n;
        for(int i=0;i<req-1;i++){
            temp=temp->next;
        }
        if(temp->next) temp->next=temp->next->next; 
        return head;       
    }
};