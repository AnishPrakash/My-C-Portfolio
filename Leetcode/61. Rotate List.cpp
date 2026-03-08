struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    
    struct ListNode* current = head;
    int len = 1;
    while (current->next) {
        current = current->next;
        len++;
    }
    
    current->next = head;
    k = k % len;
    int stepsToNewTail = len - k;
    
    struct ListNode* newTail = current;
    while (stepsToNewTail-- > 0) {
        newTail = newTail->next;
    }
    
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    
    return newHead;
}