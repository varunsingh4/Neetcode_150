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
    unordered_map<Node*,Node*>m1;
    Node* copyRandomList(Node* head) {
        //intuition is to store the copy in a map,we are using map because random is pointing to many nodes and we want that each node is copied exactly once..after copyint the original node we recursively call the next node;
        
     //algo first take a hashmap to store each copy and if on recursivley calling we are again getting the head we have to return 
     
     if(head==NULL)
     {
        return NULL;
     }
     if(m1.count(head))
     {
        return m1[head];   //if it is already present u dont need to copy it directly return 
     }
     Node*copy=new Node(head->val);
     m1[head]=copy;
     copy->next=copyRandomList(head->next);
     copy->random=copyRandomList(head->random);

     return copy;
     
    }
};
