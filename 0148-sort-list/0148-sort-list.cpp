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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* mid = getMiddle(head);  // Find the middle node
        ListNode* left = head;            // Left half of the list
        ListNode* right = mid->next;      // Right half of the list
        mid->next = nullptr;              // Split the list into two parts

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

private:
    ListNode* getMiddle(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (left && right) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        if (left) current->next = left;
        if (right) current->next = right;
        
        ListNode* result = dummy->next;
        delete dummy;  
        return result;
    }
};
