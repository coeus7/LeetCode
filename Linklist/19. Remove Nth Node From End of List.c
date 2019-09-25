/**
Detail: Use two pointer , p1 is N after p2, when p2 move to the end , p1 is the last N node
*/


/**
Note: Creat a tag node and point to head for the case :
List:[1] N:1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = NULL;
    struct ListNode* tag = NULL;
    int i = 0;
    
    tag = (struct ListNode*)malloc(sizeof(struct ListNode));
    tag ->next = head;
    p1 = tag;
    p2 = tag;
    
    
    for(i = n; i > 0; i--)
    {
        if(p2 != NULL)
        {    
            p2 = p2->next;    
        }
    }
    
    while(p2->next != NULL)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    
    p1->next = p1->next->next;

	p1 = tag->next;
	
	free(tag);
	
    return p1;
}

