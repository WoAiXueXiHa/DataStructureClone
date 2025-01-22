//203 给你一个链表的头节点head和一个整数 val 
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

//142. 环形链表2
/*typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    ListNode* fast, *slow;
    //链表为空，直接返回
    if(head == NULL){
        return NULL;
    }
    //判断链表是否带环
    bool cylce = false;
    fast = slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            cylce = true;
            break;//相遇了直接退出
        }
    }
    //不带环直接返回空
    if(cylce == false) return NULL;
    //带环，找入口点，根据公式L = C - X
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}*/

//面试题02.04.分割链表
/*typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    //创建大小链表的头和尾，这里我采用带哨兵位，避免空链表的讨论
    ListNode* greaterhead, *shorterhead;
    ListNode* greatertail, *shortertail;
    //分别给头尾开辟内存空间
    greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
    shorterhead = shortertail = (ListNode*)malloc(sizeof(ListNode));
    //判断原链表是否为空
    if(head == NULL){
        return NULL;
    }
    //创建临时变量来遍历原链表
    ListNode* pcur = head;
    while(pcur){
        //小于x，尾插到小链表
        if(pcur->val < x){
            shortertail->next = pcur;
            shortertail = shortertail->next;
        }
        //大于等于x，尾插到大链表
        else{
            greatertail->next = pcur;
            greatertail = greatertail->next;
        }
        //继续遍历原链表
        pcur = pcur->next;
    }
     //避免成环
    greatertail->next = NULL;
    //大小判断完成，链接小链表的尾和大链表的头
    shortertail->next = greaterhead ->next;
    //手动开辟内存空间，不使用时需要手动释放
    ListNode* ret = shorterhead->next;
    free(greaterhead);
    free(shorterhead);

    return ret;
}*/

//160.相交链表
/*typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //创建临时变量遍历两个链表
    ListNode* pcurA, *pcurB;
    pcurA = headA, pcurB = headB;
    //记录两个链表长度
    int lenA = 0;
    int lenB = 0;

    while(pcurA){
        lenA++;
        pcurA = pcurA->next;       
    }
    while(pcurB){
        lenB++;
        pcurB = pcurB->next;
    }
    //记录长度差
    int datance = abs(lenA - lenB);
    //没有交点
    if(pcurA != pcurB){
        return NULL;
    }
    //假设法，认为一个链表长，一个短，再用if语句判断假设是否正确
    ListNode* longlist = headA;
    ListNode* shortlist = headB;

    if(lenB > lenA){
        longlist = headB;
        shortlist = headA;
    }
    //长的先走长度差
    while(datance--){
        longlist = longlist->next;
    }
    //两个链表不相等，一直走下去，找到交点
    while(longlist != shortlist){
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return shortlist;
}*/

//138.随机链表的复制
/*
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    Node* pcur = head;
    //拷贝链表并尾插到原链表之后
    while (pcur) {
        //创建新的节点
        Node* newnode = (Node*)malloc(sizeof(Node));
        //拷贝原节点的值到新节点
        newnode->val = pcur->val;
        //尾插到原节点之后
        newnode->next = pcur->next;
        pcur->next = newnode;
        //迭代遍历原链表
        pcur = newnode->next;
    }

    //控制newnode的random
    pcur = head;
    while (pcur) {
        Node* newnode = pcur->next;

        if (pcur->random == NULL) {
            newnode->random = NULL;
        }
        else {
            newnode->random = pcur->random->next;
        }
        //迭代遍历原链表
        pcur = newnode->next;
    }

    //链接拷贝链表并恢复原链表
    pcur = head;
    //创建拷贝链表的头和尾
    Node* newhead, * newtail;
    newhead = newtail = NULL;
    while (pcur) {
        Node* newnode = pcur->next;
        Node* next = newnode->next;
        //判断新链表是否为空
        if (newtail == NULL) {
            newhead = newtail = newnode;
        }
        //尾插
        else {
            newtail->next = newnode;
            newtail = newtail->next;
        }
        //迭代
        pcur->next = next;
        //恢复原链表
        pcur = next;
    }
    return newhead;
}*/