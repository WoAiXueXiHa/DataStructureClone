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
