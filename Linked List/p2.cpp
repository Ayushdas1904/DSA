#include <iostream>
using namespace std;

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
private:
    void reverseList(ListNode *&head, ListNode *&curr)
    {
        if (curr == NULL || curr->next == NULL)
        {
            return;
        }

        ListNode *prev = NULL;
        ListNode *forward = NULL;

        while (curr != NULL)
        {
            forward = curr->next; // Save the next node
            curr->next = prev;    // Reverse the link
            prev = curr;          // Move prev to current
            curr = forward;       // Move to next node
        }
        head = prev;
    }

public:
    bool isPalindrome(ListNode *&head)
    {
        ListNode *head2 = head;
        ListNode *curr = head;
        reverseList(head, curr);
        if (curr == head2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    
    isPalindrome(head)

    return 0;
}