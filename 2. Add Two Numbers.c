/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* rsl = NULL;
    struct ListNode* p1 = NULL;
    struct ListNode* q1 = NULL;
    int add = 0, carry = 0, flag = 0;
    
    p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if(p1)
    {
        p1->next = NULL;
    }
    
    rsl = p1;
    flag = 1;
    while(l1 && l2)
    {
        if(1 == flag)
        {
            add = l1->val + l2->val;
            if(add > 9)
            {
                p1->val = add % 10;
                carry = add / 10;
            }
            else
            {
                p1->val = add;
            }
            flag = 0;
        }
        else
        {
            q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
            q1->next = NULL;
            add = l1->val + l2->val + carry;
            carry = 0;
            if(add > 9)
            {
                q1->val = add % 10;
                carry = add / 10;
            }
            else
            {
                q1->val = add;
            }
            p1->next = q1;
            p1 = q1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1)
    {
        q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->next = NULL;
        add = l1->val + carry;
        carry = 0;
        if(add > 9)
        {
            q1->val = add % 10;
            carry = add / 10;
        }
        else
        {
            q1->val = add;
        }
        p1->next = q1;
        p1 = q1;
        l1 = l1->next;
    }
    
    while(l2)
    {
        q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->next = NULL;
        add = l2->val + carry;
        carry = 0;
        if(add > 9)
        {
            q1->val = add % 10;
            carry = add / 10;
        }
        else
        {
            q1->val = add;
        }
        p1->next = q1;
        p1 = q1;
        l2 = l2->next;
    }
    
    if(carry != 0)
    {
        q1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        q1->val = carry;
        q1->next = NULL;
        p1->next = q1;
    }
    return rsl;
}