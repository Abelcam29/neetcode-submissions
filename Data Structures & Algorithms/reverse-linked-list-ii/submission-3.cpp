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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right <= left)
        {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* le = dummy;
        for(int i = 1; i < left; i++)
        {
            le = le->next;
        }
        ListNode* prev = le->next;
        ListNode* ri = prev;
        ListNode* lef = nullptr;

        for(int i = 0; i <= right - left; i++)
        {
            ListNode* curr = ri->next;
            ri->next = lef;
            lef = ri;
            ri = curr;
        }

        le->next = lef;
        prev->next = ri;

        return dummy->next;
    }
};