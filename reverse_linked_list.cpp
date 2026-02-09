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
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        //intuition is to make 3 pointers prev curr and next try to save the rest od the list firsr since it shouldnt be damaged after that reverse the link make the curr->next pointer pointing to prev and then increment prev curr and next
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;
        
    }
};
