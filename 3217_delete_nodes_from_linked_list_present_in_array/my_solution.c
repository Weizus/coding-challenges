/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// #define TABLE_SIZE 100,000

typedef struct {
    struct ListNode **table;
} HashSet;

int hash(int value, int numsSize) {
    return value % numsSize;
}

HashSet* createHashSet(int* nums, int numsSize) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    set->table = (struct ListNode**)malloc(numsSize * (sizeof(struct ListNode*)));

    for (int i = 0; i < numsSize; i++) {
        set->table[i] = NULL;
    }

    return set;
}

void putSet(HashSet* set, int value, int numsSize) {
    int indx = hash(value, numsSize);
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = value;
    new_node->next = NULL;

    // get Node pointer and look through the set for duplicates
    struct ListNode* currNode = *(set->table + indx);
    // here we see that at that index a value exists already
    while (currNode != NULL) {
        if (currNode->val == value) {
            free(new_node);
            return;
        }
        currNode = currNode->next;
    }

    // No duplicate or first elem so just add it at the head of the bucket
    new_node->next = *(set->table + indx);
    *(set->table + indx) = new_node;
}

/* Must return 0/1 */
int contains(HashSet* set, int value, int numsSize) {
    int indx = hash(value, numsSize);
    struct ListNode* currNode = *(set->table + indx);

    // iterate list
    while (currNode != NULL) {
        if (currNode->val == value) {
            return 1;
        }
        currNode = currNode->next;
    }
    return 0;
}

/* Must return 0 on success */
int freeHashSet(HashSet* set, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        struct ListNode* bucket = *(set->table + i);
        while (bucket != NULL) {
            struct ListNode* node = bucket;
            bucket = bucket->next;
            free(node);
        }
    }
    free(set->table);
    free(set);
    return 0; //Success
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    // Edge Cases
    if (head == NULL) {
        return NULL;
    } else if (numsSize == 0) {
        return NULL;
    } else if (nums == NULL) {
        return NULL;
    }
    // Create the HashSet from nums
    HashSet* numsSet = createHashSet(nums, numsSize);
    // forgot I actually need to put the values in
    for (int i = 0; i < numsSize; i++) {
        putSet(numsSet, *(nums + i), numsSize);
    }
    // iterate the list
    struct ListNode* prevNode = NULL;
    struct ListNode* currNode = head;
    struct ListNode* new_list = NULL;
    while (currNode != NULL) {
       if (contains(numsSet, currNode->val, numsSize) == 1) {
           prevNode = currNode;
           currNode = currNode->next;
           free(prevNode);
       } else {
           if (new_list == NULL) {
               new_list = currNode;
               head = new_list;
           } else {
               new_list->next = currNode;
               new_list = new_list->next;
           }
           currNode = currNode->next;
       }
    }

    freeHashSet(numsSet, numsSize);
    return head;
}
