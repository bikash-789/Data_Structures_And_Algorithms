/*
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.
Follow a recursive approach to solve this.

Note:
Assume that the Indexing for the linked list always starts from 0
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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int findNodeRec(Node *head, int val)
{
    //base case
    if(head==NULL) return -1;

    //recursive call
    int smallAns = findNodeRec(head->next, val);
    if(head->data==val) return 0;
    else if(smallAns>=0) return smallAns+1;
    return smallAns;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}