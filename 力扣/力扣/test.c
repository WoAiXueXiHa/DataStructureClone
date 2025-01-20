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

//206反转链表 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
//typedef struct ListNode ListNode;
//struct ListNode* reverseList(struct ListNode* head) {
//	  //创建三个指针 初始花 prev指向NULL pcur指向head next指向head->next
//    ListNode* prev, * pcur, * next;
//    prev = NULL;
//	  //检查给的链表是否为空
//    if (head == NULL) {
//        return NULL;
//    }
//	  //不为空 初始化
//    pcur = head;
//    next = head->next;
//    //循环条件 因为pcur是从head开始的 所以pcur不能NULL
//    while (pcur) {
//        //三个指针相继往后移动 并改变指向
//        pcur->next = prev;
//        prev = pcur;
//        pcur = next;
//        //pcur到尾 next已经是NULL了 需要判断
//        if (next != NULL)
//            next = next->next;
//    }
//
//    return prev;
//}

//876. 链表的中间结点
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head) {
//    ListNode* fast, * slow;
//    fast = slow = head;
//
//    while (fast && fast->next) {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

//141. 环形链表
//typedef struct ListNode ListNode;
//bool hasCycle(struct ListNode* head) {
//    ListNode* fast, * slow;
//    if (head == NULL) {
//        return false;
//    }
//    fast = slow = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow) {
//            return true;
//        }
//    }
//    return false;
//}