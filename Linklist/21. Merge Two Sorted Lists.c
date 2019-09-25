/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*************************************************************************
Method 1: Recusion（递归）
if(l1->val < l2->val)
	l1->next = merge(l1->next,l2)
else
	l2->next = merge(l1,l2->next)

终止条件： l1或者l2为空
时间复杂度：O(len(l1) + len(l2))
空间复杂度：O(len(l1) + len(l2))
*************************************************************************/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
    {
        return l2;
    }
    else if(l2 == NULL)
    {
        return l1;
    }
    else
    {
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next,l1);
            return l2;
        }
    }

}

/*************************************************************************
Method 2: Iteration（迭代）
creat一个哨兵，逐个判断l1 & l2 中值较小的节点，加入以prehead 为头节点的链表中
if(l1->val < l2->val)
	prehead->next = l1
else
	prehead->next = l2

时间复杂度：O(len(l1) + len(l2))
空间复杂度：O(len(l1) + len(l2))
*************************************************************************/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p = NULL;
    struct ListNode* prehead  = NULL;
    
    prehead =  (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if(prehead == NULL)
    {
        return NULL;
    }
    
    p = prehead;
    
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            p->next = l1;
            l1 = l1->next;
            
        } 
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    
    if(l1 == NULL)
    {
        p->next = l2;
    }
    else if(l2 == NULL)
    {
        p->next = l1;
    }
    else
    {
        p->next = NULL;
    }
    
    p = prehead->next;
    
    free(prehead);
    
    return p;
}
