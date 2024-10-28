// https://leetcode.com/problems/add-two-numbers/

// Digit-by-digit addition with carry
// Time complexity: O(max(m,n))
// Space complexity: O(max(m,n))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
        }

        return dummy.next;
    }
};



// Recursive
// Time complexity: O(max(m,n))
// Space complexity: O(max(m,n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (!l1 && !l2 && carry == 0) return nullptr;
        
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        ListNode* resultNode = new ListNode(sum % 10);
        
        resultNode->next = addTwoNumbers(
            l1 ? l1->next : nullptr, 
            l2 ? l2->next : nullptr, 
            sum / 10
        );
        return resultNode;
    }
};
