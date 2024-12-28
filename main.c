#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;

    return temp;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->val);
        current = current->next;
        if (current != NULL) {
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    struct ListNode* result = swapPairs(head);

    printList(result);

    // Clean up the memory
    while (result != NULL) {
        struct ListNode* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}