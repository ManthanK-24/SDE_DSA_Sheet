
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
    ListNode* iterative(ListNode* l1, ListNode* l2){
        
        if(!l1 && !l2)return NULL;
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode* ptr = l1;
        
        if(l1->val > l2->val)
        {
            ptr = l2;
            l2 = l2->next;
        }
        else
        {
            l1 = l1->next;
        }
        ListNode* cur = ptr;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(!l1)
            cur->next = l2;
        else
            cur->next = l1;
        
        return ptr;
    }
    ListNode * recursive(ListNode* l1, ListNode* l2){
        
        // Recursive
        
        if(!l1 && !l2)return NULL;
        
        if(!l1)return l2;
        
        if(!l2)return l1;
        
        if(l1->val<=l2->val)
        {
            l1->next = recursive(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = recursive(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // return recursive(l1,l2);
        
        return iterative(l1,l2);
        
    }
};
