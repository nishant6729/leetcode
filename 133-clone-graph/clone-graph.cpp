class Solution {
public:
    void dfs(Node* root, Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == NULL || root == NULL) return;

        visited[node] = root; // map original node to its clone

        for (auto& temp : node->neighbors) {
            if (visited.find(temp) != visited.end()) {
                // already cloned, just connect it
                root->neighbors.push_back(visited[temp]);
                continue;
            }
            Node* n = new Node(temp->val);
            root->neighbors.push_back(n);
            dfs(n, temp, visited);
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* root = new Node(node->val);
        unordered_map<Node*, Node*> visited; // original -> clone
        dfs(root, node, visited);
        return root;
    }
};
