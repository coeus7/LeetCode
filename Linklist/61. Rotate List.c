/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/****************************************************************************
Method:
1 -> 2 -> 3 -> 4 -> 5
找到rotation k次之后的头节点： n - k 即可
****************************************************************************/

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* pre = NULL;
    struct ListNode* ptr = NULL;
    struct ListNode* prehead = NULL;
    int n = 0, temp = 0;
    
    if(!head || k == 0)
    {
        return head;    
    }
    
    prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if(!prehead)
    {
        return NULL;
    }
    else
    {
        prehead->next = head;
    }
    
    pre = prehead;
    ptr = prehead;
    
    while(pre->next != NULL)
    {
        pre = pre->next;
        n++;
    }
    
	// rotation n == rotation zero
    k = k % n;
    
    if( k == 0)
    {
        return head;
    }
    
    pre = prehead;
    while(ptr->next != NULL)
    {
        if(k > 0)
        {
            k--;
        }
        else
        {
            pre = pre->next;
        }
        ptr= ptr->next;
    }
    
    prehead->next = pre->next;
    ptr->next = head;
    pre->next = NULL;
    
    ptr = prehead->next;
    free(prehead);
    
    return ptr;
    
}

