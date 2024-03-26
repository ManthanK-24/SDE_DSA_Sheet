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
        
        // Brute1 TC:O(n*m) SC:O(1) 
        // Brute2 TC:O(n+m) SC:O(n+m)
        
        // Optimized
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b)
        {
            a = a==NULL?headB:a->next;
            b = b==NULL?headA:b->next;
        }
        return a;
        
    }
};
