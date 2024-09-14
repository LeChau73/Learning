#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

/* CÁCH MỚI: LẤY ĐƯỢC SỐ THÌ XỬ LÝ LUÔN */
/* STATUS: CHƯA LÀM */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* Solution for new ideal */
        /* Each elements when extract from list will be have caculated and add into new list */
        /*  */
        int num_l1 = 0, num_l2 = 0, sum = 0, new_num = 0;
        bool flag = 0;
        ListNode* head = new ListNode();
        ListNode* itr = new ListNode();
        head = NULL;
        // l1 == NULL && l2 == NULL && flag == 0
        // Thì thoát khỏi while
        // 1 && 0 && 0
        while ( (l1 != NULL) || (l2 != NULL) || (flag != 0) )
        {
            // tang phan tu trong lisst
            if (l1 != NULL)
            {
                num_l1 = l1->val;
                l1 = l1->next;
            }        
            else {
                num_l1 = 0;
            }
               
            if (l2 != NULL)
            {
                num_l2 = l2->val;
                l2 = l2->next;
            }
            else
                num_l2 = 0;
       
            sum = num_l1 + num_l2 + flag;
            if (sum >= 10)
            {
                // sum > 10
                flag = 1;
                new_num = sum - 10;
            }
            else
            {
                // sum < 10
                new_num = sum;
                flag = 0;
            }
            // add vào list
            ListNode* new_node = new ListNode(new_num);
            if (head == NULL) {
                head = new_node;
                itr = head;
            }
            else {
                while (itr->next != NULL) {
                    itr = itr->next;
                }
                itr->next = new_node;
            }
            
        }
        return head;
    }
};

int main() {

    int a[] = { 1,0,0,0,0,0,0,0,0,1 };
    int b[] = { 5,6,4 };
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);
    ListNode* l1 = new ListNode[size_a];
    ListNode* l2 = new ListNode[size_b];
    ListNode* l3;


    

    for (int i = 0; i < size_a; i++) {
        if (i == (size_a - 1))
            l1[i].next = NULL;
        else {

            l1[i].next = &l1[i + 1];
        }
        l1[i].val = a[i];
    }
    for (int i = 0; i < size_b; i++) {
        if (i == (size_b - 1))
            l2[i].next = NULL;
        else {

            l2[i].next = &l2[i + 1];
        }
        l2[i].val = b[i];

    }

    Solution so;
    l3 = so.addTwoNumbers(l1, l2);

    cout << "ARR: ";
    for (auto itr = l3; itr != NULL; itr = itr->next) {
        cout << itr->val;
    }
    cout << endl;


    ListNode* itr = new ListNode();
    itr = l3;
    while (itr != NULL)
    {
        // Phan tu tiep theo
        itr = itr->next;
        // Xoa phan tu cu
        delete l3;
        // Luu lai phan tu cu
        l3 = itr;
    }

    delete[] l2;
    delete[] l1;


    return 0;
}