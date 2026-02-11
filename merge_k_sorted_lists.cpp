class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //bruthe force:-1)take a vector add all nodes to that vector
        //2) sort the vector
        //3)add all the nodes to the linked list the new linked list will contain all the nodes of the merged linked lists in the sorted fashion
        int m = lists.size();
        ListNode*dummy = new ListNode(0);
        ListNode*tail=dummy;
        vector<int>nodes;
        for(ListNode*lst:lists)
        {
            while(lst)
            {
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }
        sort(nodes.begin(),nodes.end());
        for(int i=0;i<nodes.size();i++)
        {
            tail->next=new ListNode(nodes[i]);
            tail=tail->next;
        }
        return dummy->next;    
    }


};
