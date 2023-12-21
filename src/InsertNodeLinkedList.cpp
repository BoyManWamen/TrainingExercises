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

Node* insertNode(Node* head, std::string value, int idx) {
  Node* current = head;
  Node* previous = nullptr;
  Node* newNode = new Node(value);
  
  if (idx == 0) {
    newNode->next = head;
    return newNode;
  }
  
  int counter = 0;
  
  while (current != nullptr || previous != nullptr) {
    if (counter == idx) {
      previous->next = newNode;
      newNode->next = current;
      break;
    }
    
    counter++;
    previous = current;
    current = current->next;
  }
  
  return head;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
