#include <iostream>
using namespace std;

class Node
{
public:
        int data, priority;
        Node *next;
        Node *prev;

        Node(int d, int p)
        {
                data = d;
                priority = p;
                next = prev = NULL;
        }
};

void push(Node *&head, int data, int priority)
{
        if (head == NULL)
        {
                Node *newNode = new Node(data, priority);
                head = newNode;
                return;
        }

        Node *node = new Node(data, priority);
        Node *temp = head;
        Node *parent = NULL;
        while (temp != NULL && temp->priority <= priority)
        {
                parent = temp;
                temp = temp->next;
        }

        if (parent == NULL)
        {
                node->next = head;
                head->prev = node;
                head = node;
        }
        else if (temp == NULL)
        {
                parent->next = node;
                node->prev = parent;
        }
        else
        {
                parent->next = node;
                node->prev = parent;
                node->next = temp;
                temp->prev = node;
        }
}