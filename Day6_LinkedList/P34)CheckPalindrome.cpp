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
    ListNode* reverse(ListNode* head){
        
        ListNode* prev = NULL;
        
        while(head!=NULL)
        {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        // Brute TC:O(n) SC:O(n)
        
        ListNode* fast = head, *slow = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL)slow=slow->next;
        
        fast = head;
        slow = reverse(slow);
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            {
                return false;
            }
            slow = slow ->next;
            fast = fast->next;
        }
         return true;   
    }
};
