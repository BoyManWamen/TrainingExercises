#include <string>
#include <stack>

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

bool treeIncludes(Node* root, std::string targetVal) {
  std::stack<Node*> stack;
  
  if (root != nullptr) {
    stack.push(root);
  }
  
  while (stack.size() > 0) {
    Node* current = stack.top();
    stack.pop();
    
    if (current->val == targetVal) {
      return true;
    } else {
      if (current->right != nullptr) {
        stack.push(current->right);
      }
      if (current->left != nullptr) {
        stack.push(current->left);
      }
    }
    
  }
  
  return false;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
