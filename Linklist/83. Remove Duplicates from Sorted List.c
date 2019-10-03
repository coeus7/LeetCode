/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* ptr = NULL;
    struct ListNode* prehead = NULL;
    
    if(head == NULL)
    {
        return head;
    }
    
    prehead =  (struct ListNode*)malloc(sizeof(struct ListNode));
    if(prehead == NULL)
    {
        return NULL;
    }
    
    prehead->next = head;
    pre = prehead;
    ptr = head;
    
    while(ptr->next)
    {
        if(ptr->val != ptr->next->val)
        {
            if(pre->next == ptr)
            {
                pre = ptr;
            }
            else
            {
                pre->next = ptr;
                pre = pre->next;
            }
        }
        
        ptr = ptr->next;
    }
    
    /*handle for the last n node is the same val, such as [1,2,3,3]*/
    if(pre->next == ptr)
    {
        pre = ptr;
    }
    else
    {
        pre->next = ptr;
        pre = pre->next;
    }
    
    ptr = prehead->next;
    free(prehead);
    
    return ptr;

}