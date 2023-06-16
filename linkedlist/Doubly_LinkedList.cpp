#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtHead(Node *&head, int d)
{
    Node *node = new Node(d);
    node->next = head;
    head->prev = node;

    head = node;
    node->prev = NULL;
}

void insertAtEnd(Node *&head, int d)
{
    Node *node = new Node(d);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    node->next = NULL;
}

void insertAtPosition(Node *&head, int d, int pos)
{

    Node *temp = head;

    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *node = new Node(d);

    node->next = temp->next;
    node->next->prev = node;

    temp->next = node;
    node->prev = temp;
}
void Delete(Node *&head, int pos)
{
    // head node
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;

        Node* curr = head;
        Node* previous = NULL;

        while (cnt < pos)
        {
            previous = curr;
            curr = curr->next;
            cnt++;
        }
        previous->next = curr->next;
        curr->next->prev = previous;
        curr->prev = NULL;
        curr->next = NULL;
    }
}
int getLength(Node *head)
{
    int len = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void Print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;

    Print(head);

    // cout << "Length of LL : " << getLength(head) << "\n";

    insertAtHead(head, 20);
    Print(head);

    insertAtEnd(head, 30);
    Print(head);

    insertAtPosition(head, 15, 2);
    Print(head);

    Delete(head, 3);
    Print(head);
}