/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;

        ListNode *temp1 = headA;
        while (temp1->next != NULL)
        {
            len1++;
            temp1 = temp1->next;
        }

        ListNode *temp2 = headB;
        while (temp2->next != NULL)
        {
            len2++;
            temp2 = temp2->next;
        }

        if (temp1->val != temp2->val)
            return NULL;

        len1++;
        len2++;
        temp1 = headA;
        temp2 = headB;

        if (len1 > len2)
        {
            while (len1 != len2)
            {
                temp1 = temp1->next;
                len1--;
            }
            headA = temp1;
        }

        else
        {
            while (len1 != len2)
            {
                temp2 = temp2->next;
                len2--;
            }
            headB = temp2;
        }

        while(len1 > 0)
        {
            if(headA == headB)
                return headA;
            
            headA = headA->next;
            headB = headB->next;
            len1--;
        }

        return NULL;
    }
};