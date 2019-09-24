/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* pb = NULL;

	//终止条件
    if(!head || !head->next)
        return head;

	//以下三行为调用过程
    pb = head->next;

	//返回值，返回值为后面n-2个节点排好序之后的结果
    head->next = swapPairs(pb->next);
	
    pb->next = head;
    
    return pb;
}

