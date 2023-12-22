#include <string>
#include <vector>
#include <queue>

class Node {
  public:
    std::string val;
    Node* left;
    Node* right;

    Node(std::string initialVal) {
      val = initialVal;
      left = nullptr;
      right = nullptr;
    }
};

std::vector<std::string> breadthFirstValues(Node* root) {
  std::vector<std::string> values;
  std::queue<Node*> queue;
  
  if (root != nullptr) {
    queue.push(root);
  }
  
  while (queue.size() > 0) {
    Node* current = queue.front();
    values.push_back(current->val);
    queue.pop();
    
    if (current->left != nullptr) {
      queue.push(current->left);
    }
    
    if (current->right != nullptr) {
      queue.push(current->right);
    }
    
  }
  
  return values;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
