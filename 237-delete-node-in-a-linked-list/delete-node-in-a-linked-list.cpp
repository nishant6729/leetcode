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
    void deleteNode(ListNode* node) {
       // Actual me whi node nhi htayi hai 

       node->val=(node->next)->val;

       node->next=node->next->next;
    }
};