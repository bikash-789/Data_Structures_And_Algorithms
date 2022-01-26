/*
You have been given a singly linked list of integers along with an integer 'N'.
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.

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

int countNodes(Node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

Node* appendLastNToFirst(Node* head, int n){
    //find the last node
    if(!head || n==0) return head;
    Node* lastNode = NULL,  *tempHead = head, *newHead=NULL;
    
    while(tempHead->next != NULL)
    {
        tempHead=tempHead->next;
    }
    lastNode=tempHead;
    //iterate through N-n nodes and break the link from N-n th node to remaining nodes
    int N = countNodes(head);
    int r = N-n;
    tempHead=head;
    while(r)
    {
        if(r==1)
        {
            newHead=tempHead->next;
            tempHead->next = NULL;
        }
        r--;
        tempHead=tempHead->next;
    }

    lastNode->next=head;
    head=newHead;
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}