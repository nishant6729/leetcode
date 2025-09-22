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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        while(ptr1 && ptr2){
            ListNode* temp;
            if(ptr1->val<=ptr2->val){
                temp=new ListNode(ptr1->val);
                ptr1=ptr1->next;
            }
            else{
                temp=new ListNode(ptr2->val);
                ptr2=ptr2->next;
            }

            dummy->next=temp;
            dummy=temp;
        }
        while(ptr1){
            ListNode* temp=new ListNode(ptr1->val);
            dummy->next=temp;
            dummy=temp;
            ptr1=ptr1->next;
        }
        while(ptr2){
            ListNode* temp=new ListNode(ptr2->val);
            dummy->next=temp;
            dummy=temp;
            ptr2=ptr2->next;
        }
        return head->next;
    }
};