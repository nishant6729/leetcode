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
    void reverse(ListNode* start,ListNode* end){
        ListNode* prev=NULL;
        ListNode* curr=start;
        ListNode* nxt=curr->next;

        while(curr!=end){
            curr->next=prev;

            prev=curr;
            curr=nxt;

            if(nxt) nxt=nxt->next;

        }
        curr->next=prev;

        

         
    }
     int calculateSize(ListNode* head){
        ListNode* temp=head;
        int s=0;
        while(temp){
            temp=temp->next;
            s++;
        }

        return s;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int s=calculateSize(head);

        ListNode* start=head;

        ListNode* end=head;

        ListNode* prevStart=new ListNode(-1);

        ListNode* dummy=NULL;  

        int count=s/k;

        int pairLiye=k*count;

        ListNode* finalEnd=head;

        for(int i=0;i<pairLiye;i++){
            finalEnd=finalEnd->next;
        }

        while(count--){

            for(int i=0;i<k-1;i++){
                end=end->next;
            }

            if(!dummy){
                dummy=end;
            }
            ListNode* temp=end->next;

            reverse(start,end);

            prevStart->next=end;
            prevStart=start;

            start=temp;
            end=temp;

        }

        

        prevStart->next=finalEnd;

        return dummy;
        
    }
};