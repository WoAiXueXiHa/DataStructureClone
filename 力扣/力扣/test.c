//203 ����һ�������ͷ�ڵ�head��һ������ val 
//typedef struct ListNode ListNode;
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    ListNode* newHead, * newTail;
//    newHead = newTail = NULL;
//    ListNode* pcur = head;
//
//    while (pcur) {
//        if (pcur->val != val) {
//            //����Ϊ�գ�ͷβ��ͬ
//            if (newHead == NULL) {
//                newHead = newTail = pcur;
//            }
//            else {
//                //����Ϊ�գ�����β�ڵ��ָ���β�ڵ������
//                newTail->next = pcur;
//                newTail = newTail->next;
//            }
//        }
//        //����ָ����һ���ڵ㣬��������
//        pcur = pcur->next;
//    }
//    //�ȼ��β�ڵ��Ƿ�Ϊ�գ�֮���ٽ�β�ڵ��ÿգ����ÿ����һ����ȵ�Ԫ���Ի���뵽������
//    if (newTail != NULL) {
//        newTail->next = NULL;
//    }
//    return newHead;
//}

//206��ת���� ���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//typedef struct ListNode ListNode;
//struct ListNode* reverseList(struct ListNode* head) {
//	  //��������ָ�� ��ʼ�� prevָ��NULL pcurָ��head nextָ��head->next
//    ListNode* prev, * pcur, * next;
//    prev = NULL;
//	  //�����������Ƿ�Ϊ��
//    if (head == NULL) {
//        return NULL;
//    }
//	  //��Ϊ�� ��ʼ��
//    pcur = head;
//    next = head->next;
//    //ѭ������ ��Ϊpcur�Ǵ�head��ʼ�� ����pcur����NULL
//    while (pcur) {
//        //����ָ����������ƶ� ���ı�ָ��
//        pcur->next = prev;
//        prev = pcur;
//        pcur = next;
//        //pcur��β next�Ѿ���NULL�� ��Ҫ�ж�
//        if (next != NULL)
//            next = next->next;
//    }
//
//    return prev;
//}

//876. ������м���
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

//141. ��������
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

//142. ��������2
/*typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    ListNode* fast, *slow;
    //����Ϊ�գ�ֱ�ӷ���
    if(head == NULL){
        return NULL;
    }
    //�ж������Ƿ����
    bool cylce = false;
    fast = slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            cylce = true;
            break;//������ֱ���˳�
        }
    }
    //������ֱ�ӷ��ؿ�
    if(cylce == false) return NULL;
    //����������ڵ㣬���ݹ�ʽL = C - X
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}*/

//������02.04.�ָ�����
/*typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    //������С�����ͷ��β�������Ҳ��ô��ڱ�λ����������������
    ListNode* greaterhead, *shorterhead;
    ListNode* greatertail, *shortertail;
    //�ֱ��ͷβ�����ڴ�ռ�
    greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
    shorterhead = shortertail = (ListNode*)malloc(sizeof(ListNode));
    //�ж�ԭ�����Ƿ�Ϊ��
    if(head == NULL){
        return NULL;
    }
    //������ʱ����������ԭ����
    ListNode* pcur = head;
    while(pcur){
        //С��x��β�嵽С����
        if(pcur->val < x){
            shortertail->next = pcur;
            shortertail = shortertail->next;
        }
        //���ڵ���x��β�嵽������
        else{
            greatertail->next = pcur;
            greatertail = greatertail->next;
        }
        //��������ԭ����
        pcur = pcur->next;
    }
     //����ɻ�
    greatertail->next = NULL;
    //��С�ж���ɣ�����С�����β�ʹ������ͷ
    shortertail->next = greaterhead ->next;
    //�ֶ������ڴ�ռ䣬��ʹ��ʱ��Ҫ�ֶ��ͷ�
    ListNode* ret = shorterhead->next;
    free(greaterhead);
    free(shorterhead);

    return ret;
}*/

//160.�ཻ����
/*typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //������ʱ����������������
    ListNode* pcurA, *pcurB;
    pcurA = headA, pcurB = headB;
    //��¼����������
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
    //��¼���Ȳ�
    int datance = abs(lenA - lenB);
    //û�н���
    if(pcurA != pcurB){
        return NULL;
    }
    //���跨����Ϊһ��������һ���̣�����if����жϼ����Ƿ���ȷ
    ListNode* longlist = headA;
    ListNode* shortlist = headB;

    if(lenB > lenA){
        longlist = headB;
        shortlist = headA;
    }
    //�������߳��Ȳ�
    while(datance--){
        longlist = longlist->next;
    }
    //����������ȣ�һֱ����ȥ���ҵ�����
    while(longlist != shortlist){
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return shortlist;
}*/

//138.�������ĸ���
/*
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    Node* pcur = head;
    //��������β�嵽ԭ����֮��
    while (pcur) {
        //�����µĽڵ�
        Node* newnode = (Node*)malloc(sizeof(Node));
        //����ԭ�ڵ��ֵ���½ڵ�
        newnode->val = pcur->val;
        //β�嵽ԭ�ڵ�֮��
        newnode->next = pcur->next;
        pcur->next = newnode;
        //��������ԭ����
        pcur = newnode->next;
    }

    //����newnode��random
    pcur = head;
    while (pcur) {
        Node* newnode = pcur->next;

        if (pcur->random == NULL) {
            newnode->random = NULL;
        }
        else {
            newnode->random = pcur->random->next;
        }
        //��������ԭ����
        pcur = newnode->next;
    }

    //���ӿ��������ָ�ԭ����
    pcur = head;
    //�������������ͷ��β
    Node* newhead, * newtail;
    newhead = newtail = NULL;
    while (pcur) {
        Node* newnode = pcur->next;
        Node* next = newnode->next;
        //�ж��������Ƿ�Ϊ��
        if (newtail == NULL) {
            newhead = newtail = newnode;
        }
        //β��
        else {
            newtail->next = newnode;
            newtail = newtail->next;
        }
        //����
        pcur->next = next;
        //�ָ�ԭ����
        pcur = next;
    }
    return newhead;
}*/