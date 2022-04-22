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
    ListNode *get_mid(ListNode *head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode *slow=head , *fast=head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *rev(ListNode *head)
    {
        if(!head or !head->next)
            return head;
        
        ListNode *prev=NULL,*curr=head,*nxt;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nxt;
        }
        
        return prev;
        
        
    }
    
    bool isPalindrome(ListNode* head) {
    
        if(!head or head->next==NULL)
            return true;
        
        ListNode *m1 = get_mid(head);
        ListNode *m2 = m1->next;
        
        m1->next=NULL;
        m2=rev(m2);
        
        ListNode *curr1=head,*curr2=m2;
        
        while(curr1 and curr2)
        {            
            if(curr1->val != curr2->val)
                return false;
            
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        return true;
        
        
            
        
    }
};