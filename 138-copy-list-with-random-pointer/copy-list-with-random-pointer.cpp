/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp; // original pointing to copied
        Node* temp=head;
        while(temp){
            Node* t=new Node(temp->val);
            mp[temp]=t;

            temp=temp->next;
        }
        bool flag=true;
        Node* ans=NULL;
        while(head){
            Node* duplicate=mp[head];
            if(!duplicate) break;
            duplicate->next=mp[head->next];
            duplicate->random=mp[head->random];
            if(flag){
                ans=duplicate;
                flag=false;
            }

            head=head->next;
        }
        return ans;

    }
};