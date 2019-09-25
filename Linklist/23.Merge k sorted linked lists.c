/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*********************************************************************************
Method 1: 两两合并
时间复杂度：O(kn)
空间复杂度：O(1)
**********************************************************************************/
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i = 0;
    struct ListNode* ptr = NULL;
    
    if(listsSize  == 0)
    {
        return NULL;
    }
    ptr = lists[0];
    
    for(i = 1; i < listsSize; i++)
    {
        ptr = mergeTwoLists(ptr, lists[i]);
    }
    return ptr;
}

/*********************************************************************************
Method 1: 分治算法 + 递归
将K个链表两两配对，合并后剩余k/2个 链表，以此类推

递归：
调用过程：两两合并
返回值： 合并后的子链表
终止条件：剩余1个链表或者两个链表

时间复杂度：O(nlgK)
空间复杂度：O(1)
**********************************************************************************/

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

struct ListNode* mergehalfLists(struct ListNode** lists, int low, int high)
{
    int mid = 0;
    struct ListNode* left = NULL;
    struct ListNode* right = NULL;
    
    if(low == high)
        return lists[low];
    else if((high - low) == 1)
        return mergeTwoLists(lists[low],lists[high]);
    
    mid = (high + low) >> 1;
    
    left = mergehalfLists(lists,low,mid);
    right = mergehalfLists(lists,mid+1,high);
    return mergeTwoLists(left,right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
   
    if(listsSize == 0)
    {
        return NULL;
    }
	
    //新增api 是为了方便做递归
    return mergehalfLists(lists,0,listsSize - 1);
}




