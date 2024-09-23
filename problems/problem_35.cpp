// https://neetcode.io/problems/reverse-a-linked-list

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;

        // [1, 2, 3, 4]

        // prev = null
        // curr = {val=1, next={val=2, next={...}}}

        // prev = {val=1, next=null}
        // curr = {val=2, next={...}}

        // prev = {val=2, next={val=1,next=null}}
        // curr = {val=3, next={val=4, next=null}}

        // prev = {val=3, next={val=2, next={...}}}
        // curr = {val=4, next=null}

        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
