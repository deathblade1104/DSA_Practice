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
private:
    ListNode *merge(ListNode *h1, ListNode*h2)
    {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        
        if(h1->val<=h2->val)
        {
            h1->next=merge(h1->next,h2);
            return h1;
        }
        
        else
        {
            h2->next=merge(h1,h2->next);
                return h2;
        }
    }
    
public:
    

    ListNode *sortList(ListNode *head) {
        
        if(head==NULL or  head->next==NULL)
            return head;
        
        ListNode* slow=head, *fast=head;
        
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode  *mid2=slow->next;
        slow->next=NULL;
        
        ListNode *h1=sortList(head);
        ListNode *h2=sortList(mid2);
        
        return merge(h1,h2);        
        
        
    }
};