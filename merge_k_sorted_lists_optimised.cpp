class Solution {
public:
struct Compare{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>p1;
        ListNode*temp=new ListNode(0);

        for(ListNode*ll:lists)
        {
            if(ll!=NULL)
            {
                 p1.push(ll);

            }
           
        }
        ListNode*curr=temp;
        while(!p1.empty())
        {
            ListNode*node=p1.top();
            p1.pop();
            curr->next=node;
            curr=curr->next;
            if(node->next!=NULL)
            {
                p1.push(node->next);
            }
        }
        return temp->next;


        
    }
};
