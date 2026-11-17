
class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        if(node == nullptr) {
            return nullptr;
        }

        // If already cloned, return the existing clone
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create a new cloned node
        Node* clone = new Node(node->val);

        // Store mapping before exploring neighbors
        mp[node] = clone;

        // Clone all neighbors
        for(auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {

        if(node == nullptr) {
            return nullptr;
        }

        mp.clear();

        return dfs(node);
    }
};
