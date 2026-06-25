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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* res = new ListNode();
        ListNode* head = res;
        int value = 0;
        bool sum = false;
        while(first != nullptr || second != nullptr || sum)
        {
            value = 0;
            if(sum)
            {
                value += 1;
                sum = false;
            }
            if(first != nullptr)
            {
                value += first->val;
            }
            if(second != nullptr)
            {
                value += second->val;
            }
            if(value >= 10)
            {
                value -= 10;
                sum = true;
            }
            else
            {
                sum = false;
            }

            res->val = value;

            if(first != nullptr)
            {
                first = first->next;
            }
            if(second != nullptr)
            {
                second = second->next;
            }
            if(first != nullptr || second != nullptr || sum)
            {
                ListNode* nuevo = new ListNode();
                res->next = nuevo;
                res = nuevo;
            }
        }
        return head;
    }
};
