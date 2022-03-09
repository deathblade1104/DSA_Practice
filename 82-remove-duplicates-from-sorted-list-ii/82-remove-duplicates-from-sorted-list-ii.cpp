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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode *p= new ListNode(-1);
        p->next=head;
        
        ListNode *prev=p,*first=head,*second=head->next;
        
        while(second!=NULL)
        {
            if(first->val==second->val)
            {
                while(second!=NULL and second->val==first->val)
                second=second->next;
                
                prev->next=second;
                first=second;
                
                if(second!=NULL)
                second=second->next;
                               
            }
            
            else
            {
                prev=first;
                first=second;
                second=second->next;
            }
        }
        
        return p->next;
    }
};