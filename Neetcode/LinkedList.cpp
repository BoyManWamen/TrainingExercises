class LinkedNode {
public:
    int val;
    LinkedNode* next;

    LinkedNode(int val) : val(val), next(nullptr) {

    }

    LinkedNode(int val, LinkedNode* next) : val(val), next(next) {

    }
};

class LinkedList {
private:
    LinkedNode* head;
    LinkedNode* tail;

public:
    LinkedList() {
        head = new LinkedNode(-1);
        tail = head;
    }

    int get(int index) {
        LinkedNode* current = head->next;

        int i = 0;

        while (current != nullptr) {
            if (i == index) {
                return current->val;
            }

            i++;
            current = current->next;
        }

        return -1;
    }

    void insertHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);

        newNode->next = head->next;
        head->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    
    void insertTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);

        tail->next = newNode;
        tail = tail->next;
    }

    bool remove(int index) {
        LinkedNode* current = head;

        int i = 0;

        while (i < index && current != nullptr) {
            current = current->next;
            i++;
        }

        if (current != nullptr && current->next != nullptr) {
            if (current->next == tail) {
                tail = current;
            }

            LinkedNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            return true;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> values;

        LinkedNode* current = head->next;

        while (current != nullptr) {
            values.push_back(current->val);

            current = current->next;
        }

        return values;
    }
};
