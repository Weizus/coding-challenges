/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node_t;

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool present[100001] = {false};
    for(int i = 0; i < numsSize; i++){
        present[nums[i]] = true;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* p = &dummy;

    while(p->next!=NULL){
        if(present[p->next->val]){
            p->next = p->next->next;
        }
        else{
            p = p->next;
        }
    }
    return dummy.next;
}
