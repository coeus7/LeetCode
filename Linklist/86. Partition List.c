/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *prehead = NULL;
    struct ListNode *ptr = NULL;
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;
    struct ListNode *pre2 = NULL;
    int flag = 0;
    
    prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    prehead->next = head;
    
    p1 = prehead;
    
    ptr = head;
    
    while(ptr != NULL)
    {
        if(ptr->val < x)
        {
            p1->next = ptr;
            p1 = p1->next;
        }
        else
        {
            if(flag == 0)
            {
                pre2 = ptr;
                p2 = ptr;
                flag = 1;
            }
            else
            {
                p2->next = ptr;
                p2 = p2->next;
            }
        }
        
        ptr= ptr->next;
    }

	/* for the case , p2 is null */
    if(p2)
    {
        p2->next = NULL;
    }
    
    p1->next = pre2;
    
    ptr= prehead->next;
    
    free(prehead);
    
    
    return ptr;
}

