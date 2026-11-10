class Solution {
    unordered_map<Node*, Node*> cloned;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node has already been cloned, return its clone
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }

        // Create the clone and record it in the map before recursing
        Node* copy = new Node(node->val);
        cloned[node] = copy;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};