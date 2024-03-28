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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // My Brute TC:O(3*n) SC:O(2*n)
        if(!head)return head;
        
        ListNode* tmp = head;
        int len = 1;
        
        while(tmp->next)
        {
            len++;
            tmp=tmp->next;
        }
        
        k = k%len;
        if(k>0)
        {
            ListNode* newHead;
            tmp->next = head;
            k = len - k;
            tmp = head;
            while(k>1)
            {
                tmp = tmp->next;
                k--;
            }
            newHead = tmp->next;
            tmp->next = NULL;
          
            
           return newHead; 
        }
        
        // cout<<len<<"len #\n";
        return head;
        
        
    }
};
