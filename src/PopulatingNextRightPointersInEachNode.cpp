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

#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> queue;

        if (root != nullptr) {
            queue.push(root);
        } else {
            return nullptr;
        }

        while (queue.size() != 0) {
            Node* rightNode = nullptr;
            
            for (int i = size(queue); i > 0; i--) {
                auto current = queue.front();
                current->next = rightNode;
                queue.pop();
                rightNode = current;
                if (current->right) {
                    queue.push(current->right);
                    queue.push(current->left);
                }
            }

        }

        return root;
    }
};
