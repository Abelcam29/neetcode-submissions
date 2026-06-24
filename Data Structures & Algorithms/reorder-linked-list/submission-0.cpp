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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* shs = nullptr;

        while(secondHalf != nullptr)
        {
            ListNode* h = secondHalf->next;
            secondHalf->next = shs;
            shs = secondHalf;
            secondHalf = h;
        }
        ListNode* first = head;
        while(shs != nullptr)
        {
            ListNode* next1 = first->next;
            ListNode* next2 = shs->next;

            first->next = shs;
            shs->next = next1;
            
            first = next1;
            shs = next2;
        }
    }
};
