struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* node=head;
    for(int i=0;i<k;i++){
        if(!node) return head;
        node=node->next;
    }
    
    struct ListNode* prev=NULL;
    struct ListNode* cur=head;
    for(int i=0;i<k;i++){
        struct ListNode* nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    
    head->next = reverseKGroup(cur, k);
    return prev;
}
