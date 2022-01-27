/*
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. 
You have to do this in O(N) time complexity where N is the size of the linked list.

No need to print the list, it has already been taken care. Only return the new head to the list.
*/

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* reverseLinkedListRec(Node *head)
{
    //base case
    if(head->next==NULL || !head) return head;

    //recursive call
    Node *smallAns = reverseLinkedListRec(head->next);

    //small calculation
    Node *lastNode = smallAns;
    while(lastNode->next != NULL)
    {
        lastNode=lastNode->next;
    }
    head->next=NULL;
    lastNode->next = head;
    return smallAns;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}