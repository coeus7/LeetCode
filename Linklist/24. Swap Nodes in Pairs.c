/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* pb = NULL;

	//��ֹ����
    if(!head || !head->next)
        return head;

	//��������Ϊ���ù���
    pb = head->next;

	//����ֵ������ֵΪ����n-2���ڵ��ź���֮��Ľ��
    head->next = swapPairs(pb->next);
	
    pb->next = head;
    
    return pb;
}

