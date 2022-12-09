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
    bool isPalindrome(ListNode* head) {

        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        int c = 0;
        while (c < count / 2)
        {
            c++;
            temp = temp->next;
        }

        if (count % 2 != 0)
            temp = temp->next;

        ListNode *prev = NULL;
        ListNode *curr = temp;
        ListNode *ne;

        while (curr != NULL)
        {
            ne = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ne;
        }

        temp = prev;

        ListNode *t = head;
        while (temp != NULL)
        {
            if (temp->val != t->val)
                return false;

            temp = temp->next;
            t = t->next;
        }

        return true;
    }
};