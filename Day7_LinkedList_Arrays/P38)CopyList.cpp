/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomListUsingMemory(Node* head) {
        map<Node*, Node*> m;
        Node* ptr = head;
        while(ptr)
        {
            m[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr=head;
        while(ptr)
        {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
    Node* copyRandomList(Node* head) {
        
        if(!head)return head;
        Node* iter = head;
        
        while(iter!=NULL)
        {
            Node* copy = new Node(iter->val);
            Node* tmp = iter->next;
            
            iter->next = copy;
            copy->next = tmp;
            iter = iter->next->next;
        }
        
        iter = head;
        while(iter!=NULL && iter->next!=NULL)
        {
           // cout<<iter->val<<"# ";
            if(iter->random!=NULL)
            iter->next->random = iter->random->next;
            iter=iter->next->next;
        }
        // cout<<"\n";
        
        iter = head;
        Node* dummy = new Node(0);
        dummy->next = iter->next;
        Node* tmp = dummy;
        Node * frnt;
        while(iter!=NULL)
        {
            frnt = iter->next->next;
           tmp->next = iter->next;
           tmp = tmp->next;
            iter->next = frnt;
            
           iter = frnt;
        }
        return dummy->next;
       
    }
};
