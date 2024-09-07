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
        int number1 = 0, number2 = 0, sum = 0, square_index = 0;
        auto itr1 = l1, itr2 = l2;
        ListNode* l3;
        // Lấy giá trị trong list 1
        while (itr1 != NULL) {
            number1 += itr1->val * pow(10, square_index);
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
        int phan_nguyen = 0, phan_du = 0;
        l3 = new ListNode();
        // Tach so
        for (int i = 0; i < square_index; i++) {
            if (i == 0)
            {
                //Thằng cuối cùng thì sẽ gán next của nó bằng = NULL
                //l3[final position].next = NULL
                l3[square_index - 1].next = NULL;
            }
            else {
                // Case should not be in the last position 
                // l3[pointer of previous element].next = l3[current element]
                l3[square_index - 1 - i].next = &l3[square_index - i];
            }
            phan_nguyen = sum / pow(10, square_index - (i + 1));
            phan_du = sum % int(pow(10, square_index - (i + 1)));
            sum = phan_du;
            l3[square_index - (i + 1)].val = phan_nguyen;
        }

        return l3;

    }
};

int main() {

    int a[5] = { 2, 3, 4 , 2 , 5 };
    int b[3] = { 5, 6, 4 };
    ListNode* l1 = new ListNode[5];
    ListNode* l2 = new ListNode[3];
    ListNode* l3;


    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);

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

    for (ListNode* itr = l3; itr != NULL; itr = itr->next) {
        delete itr;
    }

    delete[] l2;
    delete[] l1;


    return 0;
}