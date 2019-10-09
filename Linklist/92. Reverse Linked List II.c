/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/* Solution：
	1-2-3-4-5
	1-3-2-4-5
	1-4-3-2-5
*/

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode* prehead = NULL;
    struct ListNode* pre = NULL;
    struct ListNode* end = NULL;
    struct ListNode* ptr = NULL;
    struct ListNode* pnext = NULL;
    
    int cur = 1;
    
    prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if(prehead == NULL)
    {
        return NULL;
    }
    
    prehead->next = head;
    pre = prehead;
    ptr = head;
    end = head;
    while(ptr && pre && end)
    {
        if(cur < m)
        {
            pre = pre->next;
            ptr = ptr->next;
            end = end->next;
        }
        else if(cur < n)
        {
            end = end->next;
        }
        else
        {
            break;
        }
        cur++;
    }
    
    end = end->next;
    
    while(ptr->next != end)
    {
        
        pnext = ptr->next;
        if(pnext == NULL)
        {
            break;
        }
        ptr->next = pnext->next;
        pnext->next = pre->next;
        pre->next = pnext;
    }
    
    ptr = prehead->next;
    free(prehead);
    return ptr;
}