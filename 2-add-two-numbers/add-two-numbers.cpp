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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;

        ListNode* ptr1=l1;
        ListNode* ptr2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(ptr1 && ptr2){
            sum=(ptr1->val)+(ptr2->val);
            int t=sum;
            sum=sum%10;
            ListNode* temp=new ListNode((sum+carry)%10);
            carry=(t+carry)/10;
            dummy->next=temp;
            dummy=temp;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1){
            sum=(ptr1->val)+(0);
            int t=sum;
            sum=sum%10;
            ListNode* temp=new ListNode((sum+carry)%10);
            carry=(sum+carry)/10;
            dummy->next=temp;
            dummy=temp;
            ptr1=ptr1->next;
            
        }
        while(ptr2){
            sum=(0)+(ptr2->val);
            int t=sum;
            sum=sum%10;
            ListNode* temp=new ListNode((sum+carry)%10);
            carry=(sum+carry)/10;
            dummy->next=temp;
            dummy=temp;
            
            ptr2=ptr2->next;
            
        }
        while(carry!=0){
            ListNode* temp=new ListNode(carry%10);
            carry=carry/10;
            dummy->next=temp;
        }
        return head->next;
    }
};