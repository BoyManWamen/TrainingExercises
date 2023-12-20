/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;

        int counter = 0;

        while (current != NULL) {
            current = current->next;
            counter++;
        }

        int nodeIndex = counter - n;

        if (nodeIndex == 0) {
            return head->next;
        }

        ListNode* temp=head,*prevNode=NULL;

        while (nodeIndex) {
            prevNode = temp;
            temp = temp->next;
            nodeIndex--;
        }

        prevNode->next = temp->next;

        return head;
    }
};
