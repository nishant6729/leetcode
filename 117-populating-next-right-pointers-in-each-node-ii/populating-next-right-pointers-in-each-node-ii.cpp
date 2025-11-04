/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qu;
        qu.push(root);
        qu.push(NULL);
        while(!qu.empty()){
            Node* temp=qu.front();
            qu.pop();
            if(!temp) continue;
            if(temp) temp->next=qu.front();
            if(temp && temp->left) qu.push(temp->left);
            if(temp && temp->right) qu.push(temp->right);
            if(qu.front()==NULL) qu.push(NULL);
        }
        return root;
    }
};