
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr = head;
        int count = 0;
        while(count<k)
        {
            if(curr==NULL)return head;
            curr=curr->next;
            
            count++;
            
        }
        
           ListNode* node = head;
            ListNode* prev = NULL;
           for(int i=0;i<k;i++)
           {
               ListNode* frnt = node->next;
               node->next = prev;
                prev = node;
                node = frnt;
            }
            head->next = reverseKGroup(node,k);
            return prev;
        
    }
};
