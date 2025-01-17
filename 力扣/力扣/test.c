//203 给你一个链表的头节点head和一个整数 val 
// 请你删除链表中所有满足Node.val == val 的节点，并返回新的头节点
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    ListNode* newHead, * newTail;
//    newHead = newTail = NULL;
//    ListNode* pcur = head;
//
//    while (pcur) {
//        if (pcur->val != val) {
//            //链表为空，头尾相同
//            if (newHead == NULL) {
//                newHead = newTail = pcur;
//            }
//            else {
//                //链表不为空，更新尾节点的指向和尾节点的内容
//                newTail->next = pcur;
//                newTail = newTail->next;
//            }
//        }
//        //继续指向下一个节点，遍历链表
//        pcur = pcur->next;
//    }
//    //先检查尾节点是否为空，之后再将尾节点置空，不置空最后一个相等的元素仍会插入到新链表
//    if (newTail != NULL) {
//        newTail->next = NULL;
//    }
//    return newHead;
//}
