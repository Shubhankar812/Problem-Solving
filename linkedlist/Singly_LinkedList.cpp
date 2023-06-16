#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int Data)
    {
        this->data = Data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *tmp = new Node(d);
    tmp->next = head;
    head = tmp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *node = new Node(d);

    tail->next = node;
    tail = node;
}

void insertAtPosition(Node *&head, int d, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void Delete(Node *&head, int pos)
{
    // if the node is a head node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;

        while(cnt < pos) {
            prev = curr;
            curr = curr->next;
            // prev = prev->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *tmp = head;

    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{

    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    print(head);
    insertAtHead(head, 15);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, 18, 3);
    print(head);

    Delete(head,3);
    print(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
}