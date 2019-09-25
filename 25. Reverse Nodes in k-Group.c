/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /****************************************************************************************
 Method 1 ：使用尾插法分组翻转
pre -> 1 -> 2 -> 3
pre -> 2 -> 3 -> 1
pre -> 3 -> 2 -> 1
 ****************************************************************************************/

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int i = 0;
    struct ListNode* pre = NULL, *next = NULL;
    struct ListNode* start = NULL, *end = NULL;
    struct ListNode* head1 = NULL;
    
    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!prehead)
    {
        return NULL;
    }
    prehead->next = head;
    
    pre = prehead;
    end = prehead;
    while(1)
    {
        for(i = 0; i < k; i++)
        {
            if(end == NULL)
                break;
            end = end->next;
        }
        
        if(end == NULL) break;
        
        head1 = pre->next;
        while(pre->next != end)
        {
            start = pre->next;
            pre->next = start->next;
            start->next = end->next;
            end->next = start;
        }
        
        end = head1;
        pre = head1;
    }
    
    head1 = prehead->next;
    
    free(prehead);
    return head1;
}

 /****************************************************************************************
 Method 2 ：递归
1 -> 2 -> 3 -> reverseKGroup
1 -> reverseKGroup
2 -> 1
3 -> 2

返回值：  分组翻转后首节点的地址
终止条件：分组翻转后最后剩余的节点数不足k个
调用过程：分组翻转
 ****************************************************************************************/
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int count = 0;
    struct ListNode* pre = NULL;
    struct ListNode* cur = NULL;
    struct ListNode* tmp = NULL;
    
    cur = head;
    pre = head;
    
    while((count != k) && (cur != NULL))
    {
        cur = cur->next;
        count++;
    }
    
    if(count == k)
    {
        cur = reverseKGroup(cur,k);
        while(count > 0)
        {
            count--;
            tmp = pre->next;
            
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }
        head = cur;   
    }
    return head;
}

