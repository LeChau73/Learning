#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


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
        int number1 = 0, number2 = 0, sum = 0;
        int square_index = 0;
        auto itr1 = l1, itr2 = l2;
        ListNode* l3;
        // Lấy giá trị trong list 1
        while (itr1 != NULL) {
            number1 = number1 * 10 + itr1->val;
            ++square_index;
            itr1 = itr1->next;
        }
        square_index = 0;
        // Lấy giá trị trong list 2
        while (itr2 != NULL) {
            number2 += itr2->val * pow(10, square_index);
            ++square_index;
            itr2 = itr2->next;
        }

        // Cộng 2 số 
        sum = number1 + number2;

        /* Tách số và thêm vào list để trả về */

        unsigned char phan_du = 0;
        long double phan_nguyen = 0;
        

        // Tach so
        // ĐK: mỗi node là 1 new phần tử mới 
        // node_new = new ListNode(value);
        ListNode* temp_last = new ListNode();
        ListNode* Head_Node = new ListNode();
        Head_Node = NULL;  // Chưa trỏ tới phần tử nào trong Node
        
        while (true)
        {
            // Tach so phan du -> 
            phan_du = fmod(sum, 10);
            phan_nguyen = sum / 10;
            sum = phan_nguyen;

            //
            ListNode* newNode = new ListNode(phan_du);
            if (Head_Node == NULL)
            {
                Head_Node = newNode; //Head_Node trỏ đến phần tử đầu tiên
                temp_last = Head_Node; // Sử dụng một biến tạm để lấy head node (dùng để duyệt phần tử)
            }
            else {
                while (temp_last->next != NULL) {
                    temp_last = temp_last->next;
                }
                temp_last->next = newNode;
            }
            if (sum == 0)
                return Head_Node;
        }
    }
};

int main() {

    int a[] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
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