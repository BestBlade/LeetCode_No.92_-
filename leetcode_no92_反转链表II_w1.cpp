/* ------------------------------------------------------------------|
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了27.83%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    vector<int> nums;
    ListNode* node = head;
    int i = 1;
    while (i++ <= n) {
        if (i <= m) {
            node = node->next;
        }
        else {
            nums.emplace_back(node->val);
            node = node->next;
        }
    }
    i = 1;
    node = head;
    while (i++ <= n) {
        if (i <= m) {
            node = node->next;
        }
        else {
            node->val = nums.back();
            nums.pop_back();
            node = node->next;
        }
    }
    return head;
}