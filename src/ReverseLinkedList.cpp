#include <string>

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};

Node* reverseList(Node* head) {
  Node* previous = nullptr;
  Node* current = head;
  
  while (current != nullptr) {
    Node* next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  
  return previous;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
