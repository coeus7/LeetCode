/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*********************************************************************************
Method 1: �����ϲ�
ʱ�临�Ӷȣ�O(kn)
�ռ临�Ӷȣ�O(1)
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
Method 1: �����㷨 + �ݹ�
��K������������ԣ��ϲ���ʣ��k/2�� �����Դ�����

�ݹ飺
���ù��̣������ϲ�
����ֵ�� �ϲ����������
��ֹ������ʣ��1�����������������

ʱ�临�Ӷȣ�O(nlgK)
�ռ临�Ӷȣ�O(1)
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
	
    //����api ��Ϊ�˷������ݹ�
    return mergehalfLists(lists,0,listsSize - 1);
}




