class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=slow->next;
        slow->next=NULL;
        ListNode*prev=NULL;
        while(temp!=NULL)
        {
           ListNode*next=temp->next;
           temp->next=prev;
           prev=temp;
           temp=next;
        }
        ListNode*temp1=head;
        ListNode*temp2=prev;
        while(temp2!=NULL)
        {
            ListNode*t1=temp1->next;
            ListNode*t2=temp2->next;
            temp1->next=temp2;
            temp2->next=t1;
            temp1=t1;
            temp2=t2;


        }

    }
};
