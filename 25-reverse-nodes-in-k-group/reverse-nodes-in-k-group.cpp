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
    ListNode* reverseKGroup(ListNode* head, int k) {
        deque<pair<ListNode*,ListNode*>> dq;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int loop=size/k;
        ListNode* start=head;
        ListNode* end=start;
        for(int i=0;i<loop;i++){
            for(int j=0;j<k;j++){
                if(end) end=end->next;
            }
            ListNode* first=reverse(start,end);
            ListNode* second=start;
            dq.push_back({first,second});
            start=end;
        }
        if(start){
            dq.push_back({start,NULL});
        }
        dq.push_back({NULL,NULL});
        ListNode* dummy=new ListNode(0);

        dummy->next=dq[0].first;
        for(int i=0;i<dq.size()-1;i++){
            if(dq[i].second) dq[i].second->next=dq[i+1].first;
            


        }
        return dummy->next;
    }
};