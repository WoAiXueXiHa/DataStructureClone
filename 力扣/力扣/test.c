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

//20.��Ч������
/*bool isValid(char* s) {
    Stack st;
    StackInit(&st);

    while (*s) {
        if (*s == '(' || *s == '{' || *s == '[') {
            StackPush(&st, *s);
        }
        else {
            //�����ű������Ŷ�
            if (StackEmpty(&st)) {
                StackDestory(&st);
                return false;
            }

            char top = StackTopVal(&st);
            StackPop(&st);

            //���Ų�ƥ��
            if ((*s == ']' && top != '[')
             || (*s == '}' && top != '{')
             || (*s == ')' && top != '('))
            {
                StackDestory(&st);
                return false;
            }
        }
        s++;
    }

    //�����ű������Ŷ�
    bool ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}*/

//225.�ö���ʵ��ջ
/*typedef struct {
    Queue q1;
    Queue q2;    
} MyStack;

//����ջ
MyStack* myStackCreate() {
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&pst->q1);
    QueueInit(&pst->q2);

    return pst;
}

void myStackPush(MyStack* obj, int x) {
    assert(obj);
    //�����ݵ���Ϊ�յĶ��� ����������ж�Ϊ�� �����ݵ�q2
    if(!QueueEmpty(&obj->q1)){
        QueuePush(&obj->q1, x);
    }
    else{
        QueuePush(&obj->q2, x);
    } 
}

int myStackPop(MyStack* obj) {
    assert(obj);

    //����&obj->q1Ϊ�գ�&obj->q2��Ϊ��
    Queue* pEmpty = &obj->q1;
     Queue* pNonEmpty = &obj->q2;
    //�������
    if(!QueueEmpty(&obj->q1)){
        pEmpty =  &obj->q2;
        pNonEmpty = &obj->q1;
    }

    while(QueueSize(pNonEmpty) > 1){
        int front = QueueFrontVal(pNonEmpty);
        QueuePush(pEmpty,front);
        QueuePop(pNonEmpty);
    }  
    int top = QueueFrontVal(pNonEmpty);
    QueuePop(pNonEmpty);
    return top; 
}

int myStackTop(MyStack* obj) {
    assert(obj);
    //ջ��Ԫ��ʵ���ǲ�Ϊ�ն��еĶ�βԪ��
    if(!QueueEmpty(&obj->q1)){
        return QueueBackVal(&obj->q1);
    }
    else{
        return  QueueBackVal(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);

    free(obj);
}

*/

//965.��ֵ������
/*bool isUnivalTree(struct TreeNode* root) {
    if(root == NULL) return true;

    if(root->left && root->val != root->left->val){
        return false;
    }

    if(root->right && root->val != root->right->val){
        return false;
    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);

}*/

//104. ��������������
/*int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;   
}*/