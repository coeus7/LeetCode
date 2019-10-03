/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
Method1: 快慢指针
本题核心是，有序链表，所以p.val 和 p.next.val 如果不相等，说明p.val 这个值链表中就没有重复的
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
                pre->next = ptr->next;
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
        pre->next = ptr->next;
    }
    
    ptr = prehead->next;
    free(prehead);
    
    return ptr;

}


/*
Method2: 递归
这里的递归其实就是while 循环去逐个查找，效率反而更低
*/
struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(head == NULL)
        return head;
    
    if(head->next && (head->val == head->next->val))
    {
        while(head && head->next && (head->val == head->next->val))
        {
            head = head->next;
        }
        return deleteDuplicates(head->next);
    }
    else
    {
        head->next =  deleteDuplicates(head->next);
    }
    
    return head;
}