/*Initialize a slow and a fast pointer at the head of the linked list.

Move the slow pointer one step at a time and the fast pointer two steps at a time. This way, when the fast pointer reaches the end of the list, the slow pointer will be at the middle.

Push the elements from the first half of the list (i.e., the elements that the slow pointer traverses) onto a stack.

If the list has an odd number of elements, skip the middle element by moving the slow pointer one step forward.

Continue moving the slow pointer one step at a time, now comparing the elements it traverses with the elements popped from the stack. If all elements match, the linked list is a palindrome.s*/

#include <bits/stdc++.h>
#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newhead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newhead = reverse(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newhead);
    return true;
}

// Example usage
int main()
{

    // Create a sample linked list
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int data;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> data;

        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        std::cout << "The linked list is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
