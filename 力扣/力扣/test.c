//203 ����һ�������ͷ�ڵ�head��һ������ val 
// ����ɾ����������������Node.val == val �Ľڵ㣬�������µ�ͷ�ڵ�
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