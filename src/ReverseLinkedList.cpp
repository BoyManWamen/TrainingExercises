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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        vector<int> numbers;

        while (current != nullptr) {
            numbers.push_back(current->val);
            current = current->next;
        }

        reverse(numbers.begin(), numbers.end());

        current = head;

        for (int i = 0; i < numbers.size(); i++) {
            current->val = numbers[i];
            current = current->next;
        }

        return head;
    }
};
