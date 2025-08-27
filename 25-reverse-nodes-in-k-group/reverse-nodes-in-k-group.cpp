class Solution {
public:
    // Proper reverse that returns new head
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev; // new head of reversed list
    }

    // Find kth node from current node
    ListNode* KthNode(ListNode* temp, int k) {
        while (temp && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroupEnd = dummy;
        ListNode* temp = head;

        while (temp) {
            ListNode* kthNode = KthNode(temp, k);
            if (!kthNode) break; // not enough nodes for reversal

            ListNode* nextGroupStart = kthNode->next;
            kthNode->next = nullptr;

            // reverse current group
            ListNode* newHead = reverse(temp);

            // connect previous group with new head
            prevGroupEnd->next = newHead;

            // connect old head (temp, now tail) with next group
            temp->next = nextGroupStart;

            // update for next iteration
            prevGroupEnd = temp;
            temp = nextGroupStart;
        }

        return dummy->next;
    }
};
