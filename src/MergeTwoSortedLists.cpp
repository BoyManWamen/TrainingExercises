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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* firstList = list1;
        ListNode* secondList = list2;

        ListNode* listHead = nullptr;

        if (firstList == nullptr && secondList != nullptr) {
            listHead = secondList;
            secondList = secondList->next;
        } else if (secondList == nullptr && firstList != nullptr) {
            listHead = firstList;
            firstList = firstList->next;
        } else if (firstList != nullptr && secondList != nullptr) {
            if (firstList->val <= secondList->val) {
                listHead = firstList;
                firstList = firstList->next;
            } else {
                listHead = secondList;
                secondList = secondList->next;
            }
        }

        ListNode* listTail = listHead;

        while (firstList != nullptr || secondList != nullptr) {
            if (firstList == nullptr) {
                listTail->next = secondList;
                secondList = secondList->next;
            } else if (secondList == nullptr) {
                listTail->next = firstList;
                firstList = firstList->next;
            } else {
                if (firstList->val <= secondList->val) {
                    listTail->next = firstList;
                    firstList = firstList->next;
                } else {
                    listTail->next = secondList;
                    secondList = secondList->next;
                }
            }

            listTail = listTail->next;
        }

        return listHead;
    }
};
