/* ------------------------------------------------------------------|
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：7 MB, 在所有 C++ 提交中击败了10.46%的用户
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
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode* pre = &dummyHead;
    for (int i = 1; i < m; i++) {
        pre = pre->next;
    }
    
    ListNode* nodeN = pre->next;
    for (int i = m; i < n; i++) {
        ListNode* next = nodeN->next;
        nodeN->next = next->next;
        //注意curr一直不会变，变的只有pre->next
        next->next = pre->next;
        pre->next = next;
    }
    return dummyHead.next;
}