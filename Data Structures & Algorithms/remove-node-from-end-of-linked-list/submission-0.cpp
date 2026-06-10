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
        ListNode* fast = head;
        ListNode* slow = head;
        int first = 0, second = 0;
        while(fast != nullptr)
        {
            fast = fast->next;
            first++;
        }
        if(first == n)
        {
            return head->next;
        }
        first = first - n;
        while(second < (first-1))
        {
            slow = slow->next;
            second++;
        }
        slow->next = slow->next->next;
        return head;
    }
};
