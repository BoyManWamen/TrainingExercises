#include <string>
#include <vector>

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};

Node* createLinkedList(std::vector<std::string> values) {
  if (values.size() == 0) {
    return nullptr;
  }
  
  Node* head = new Node(values[0]);
  Node* tail = head;
  
  for (int i = 1; i < values.size(); i++) {
    tail->next = new Node(values[i]);
    tail = tail->next;
  }
  
  return head;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
