/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        ListNode* ans=NULL;
        while(headA && headB){
            if(st.count(headA)){
                ans=headA;
                return ans;
            }
            st.insert(headA);
            headA=headA->next;
            if(st.count(headB)){
                ans=headB;
                return ans;
            }
            st.insert(headB);
            headB=headB->next;
        }  
        while(headA){
            if(st.count(headA)){
                ans=headA;
                return ans;
            }
            st.insert(headA);
            headA=headA->next;
        } 
        while(headB){
            if(st.count(headB)){
                ans=headB;
                return ans;
            }
            st.insert(headB);
            headB=headB->next;
        } 
        return ans;
    }
    
};