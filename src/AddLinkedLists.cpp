#include <vector>

class Node {
  public:
    int val;
    Node *next;

    Node(int initialVal)
    {
      val = initialVal;
      next = nullptr;
    }
};

Node *addLists(Node *head1, Node *head2) {
  Node* current1 = head1;
  Node* current2 = head2;
  
  Node* addListDummyHead = new Node(0);
  Node* addListDummyTail = addListDummyHead;
  
  int carryOver = 0;
  
  while (current1 != nullptr || current2 != nullptr) {
    int currentSum = 0 + carryOver;
    carryOver = 0;
    
    if (current1 != nullptr) {
      currentSum += current1->val;
      current1 = current1->next;
    }
    
    if (current2 != nullptr) {
      currentSum += current2->val;
      current2 = current2->next;
    }
    
    if (currentSum > 9) {
      carryOver += (currentSum / 10);
      currentSum %= 10;
    }
    
    Node* newNode = new Node(currentSum);
    
    addListDummyTail->next = newNode;
    addListDummyTail = addListDummyTail->next;
  }
  
  if (carryOver > 0) {
    addListDummyTail->next = new Node(carryOver);
  }
  
  return addListDummyHead->next;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}
