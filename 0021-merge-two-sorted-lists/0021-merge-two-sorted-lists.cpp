/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode* next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1); 
        ListNode* ans = &dummy; 

        ListNode* ptr1 = list1; 
        ListNode* ptr2 = list2; 

        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val < ptr2->val) {
                ans->next = ptr1; 
                ptr1 = ptr1->next; 
            } else {
                ans->next = ptr2; 
                ptr2 = ptr2->next; 
            }
            ans = ans->next; 
        }

        if (ptr1 != nullptr) {
            ans->next = ptr1;
        } else {
            ans->next = ptr2;
        }

        return dummy.next; 
    }
};
