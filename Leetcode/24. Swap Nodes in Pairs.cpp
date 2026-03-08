struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode* p=&dummy;
    
    while(p->next && p->next->next){
        struct ListNode* a=p->next;
        struct ListNode* b=a->next;
        
        a->next=b->next;
        b->next=a;
        p->next=b;
        
        p=a;
    }
    return dummy.next;
}
