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
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;
        
        Node *curr = head;
        
        while(curr!=NULL){
            
            Node *nxt = curr->next;
            curr->next = new Node (curr->val);
            
            curr->next->next = nxt;
            curr = nxt;
        }
        
        curr = head;
        
        while(curr!=NULL){
            curr->next->random = curr->random != NULL ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        
        
        curr = head;
        Node *curr2=curr->next;
        Node *p=curr2;
        
        while(curr and curr2 and curr->next and curr2->next)
        {
            curr->next=curr2->next;
            curr=curr->next;
            
            curr2->next=curr->next;
            curr2=curr2->next;
        }
        
        curr->next=NULL;
        //curr2->next=NULL;
        
        return p;
        
        
        
    }
};